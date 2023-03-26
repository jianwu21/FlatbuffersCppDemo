/**
 * Author: Jian Wu
 * Date: 26 Mar, 2023
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <fstream>
#include <errno.h>
#include <pthread.h>
#include <flatbuffers/flatbuffers.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <chrono>

#include "marketdata_generated.h"

/**
 * @brief  
 * @return void* 
 */
void* OnNewSession(void*);

/**
 * @brief 
 * @return 
 */
flatbuffers::FlatBufferBuilder CreateNewMessage();

/**
 * @brief 
 * @param  
 */
void send_message(int);

int main(int argv, char** argc){
    int host_port = 1101;

    struct sockaddr_in my_addr;

    int hsock;

    socklen_t addr_size = 0;
    sockaddr_in sadr;
    int t_id = 0;

    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if(hsock == -1)
    {
        std::cout << "Error initializing socket" << errno << std::endl;

        return -1;
    }

    int *p_int = new int(1);

    if((setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1 )|| 
        (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1)) 
    {
        std::cout << "Error setting options, error code: " << errno << std::endl;

        return -1;
    }

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(host_port);

    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = INADDR_ANY ;

    int bindStatus = bind(hsock, (struct sockaddr*) &my_addr, sizeof(my_addr));
    
    if (bindStatus < 0)
    {
        std::cout << "Error binding to socket, make sure nothing else is listening on this port. Error code: " << errno << std::endl;
        close(hsock);

        return -1;
    }
    
    if (listen(hsock, 10) == -1 ) 
    {
        std::cout << "Error listening " << errno << std::endl;
        close(hsock);

        return -1;
    }

    //Now lets do the server stuff
    addr_size = sizeof(sockaddr_in);
    std::cout <<  "waiting for connections..." << std::endl;

    while (true)
    {
        int *csock = new int{1};
        
        if ((*csock = accept(hsock, (sockaddr*)&sadr, &addr_size)) != -1) {
            std::cout << "-----------------------------------------------------" << std::endl;
            std::cout << "Received connection from " << inet_ntoa(sadr.sin_addr) << std::endl;
            pthread_t thread_id;
            pthread_create(&thread_id, 0, &OnNewSession, (void*)csock);
            pthread_detach(thread_id);
        } else {
            std::cout << "Error accepting, err code: " << errno << std::endl;
        }
    }
}

void* OnNewSession(void *ln){
    int *csock = (int*)ln;
    while (true) {
        send_message(*csock);

        // 250 ms
        usleep(250000);
    }
}

void send_message(int csock)
{
    flatbuffers::FlatBufferBuilder fbb = CreateNewMessage();
    int message_size = fbb.GetSize();
    
    char pkg[message_size];
    memset(pkg, 0, message_size);
    memcpy(pkg, (void*)fbb.GetBufferPointer(), message_size);

    int bytesent;
    if((bytesent = send(csock, (void*)pkg, message_size, 0)) == -1) 
    {
        std::cout << "Error sending data, error code: " << errno << std::endl;
        close(csock);

        return;
    }

    std::cout << "Sent bytes " << bytesent << std::endl;
}

int g_seq = 0;

flatbuffers::FlatBufferBuilder CreateNewMessage()
{
    flatbuffers::FlatBufferBuilder builder;

    auto trade = crypto::CreateTrade(builder, 1603, 10000);
    auto level_update = CreateLevelUpdate(builder, 1604, 5000, 2, crypto::Side_Buy);
    auto timestamp_nanos =
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::high_resolution_clock::now().time_since_epoch()).count();

    auto symbol = builder.CreateString("ETHUSDT");
    auto message1 = CreateMessage(
            builder, timestamp_nanos, symbol,
            crypto::MessageBody_LevelUpdate, level_update.Union());
    auto message2 = CreateMessage(
            builder, timestamp_nanos, symbol,
            crypto::MessageBody_Trade, trade.Union());

    std::vector<flatbuffers::Offset<crypto::Message>> messages_vector;
    messages_vector.push_back(message1);
    messages_vector.push_back(message2);
    auto messages = builder.CreateVector(messages_vector);
    auto multi_messages = CreateMultiMessage(builder, g_seq++, messages);

    builder.Finish(multi_messages);  // Serialize the root of the object.

    return builder;
}
