/**
 * Author: Jian Wu
 * Date: 26 Mar, 2023
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <fstream>

#include "marketdata_generated.h"

void OnNewMarketData(const crypto::Message *md)
{
    switch (md->body_type()) {
        case crypto::MessageBody_LevelUpdate:
        {
            std::cout << std::setw(18) << "Type: "
                      << std::setw(18) << "LevelUpdate" << std::endl;
            std::cout << std::setw(18) << "Price: "
                      << std::setw(18) << md->body_as_LevelUpdate()->price()
                      << std::endl;
            std::cout << std::setw(18) << "Size: "
                      << std::setw(18) << md->body_as_LevelUpdate()->size() << std::endl;
            break;
        }
        case crypto::MessageBody_Trade:
        {
            std::cout << std::setw(18) << "Type: "
                      << std::setw(18) << "Trade" << std::endl;
            std::cout << std::setw(18) << "Price: "      
                      << std::setw(18) << md->body_as_Trade()->price() << std::endl;
            std::cout << std::setw(18) << "Size: "       
                      << std::setw(18) << md->body_as_Trade()->size()  << std::endl;
            break;
        }
        default:
            break;
    }
}

void OnNewMessage(char *buf)
{
    auto mmd = crypto::GetMultiMessage(buf);
    auto mds = mmd->messages();
    auto message_counts = mmd->messages()->size();
    std::cout << std::setw(18) << "SeqNo: " << std::setw(18) << mmd->seq_no() << std::endl;
    for (int i = 0 ; i < message_counts; ++i)
    {
        auto md = mds->Get(i);
        std::cout << std::setw(18) << "Time(nanos): " << std::setw(18) << md->ts_nanos()            << std::endl;
        std::cout << std::setw(18) << "Instrument: "  << std::setw(18) << md->symbol()->c_str()     << std::endl;

        OnNewMarketData(md);
    }
}

int main(int argv, char** argc)
{
    int host_port = 1101;
    char* host_name = "127.0.0.1";

    struct sockaddr_in my_addr;

    int hsock;
    int err;

    hsock = socket(AF_INET, SOCK_STREAM, 0);
    
    if(hsock == -1)
    {
        printf("Error initializing socket %d\n", errno);
        close(hsock);

        return -1;
    }

    int *p_int = new int{1};

    if((setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1)||
        (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1))
    {
        printf("Error setting options %d\n", errno);
        close(hsock);
        return -1;
    }

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(host_port);

    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = inet_addr(host_name);

    if (connect(hsock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1) 
    {
        if((err = errno) != EINPROGRESS){
            std::cout << "Error connecting socket " << errno << std::endl;
            close(hsock);

            return -1;
        }
    }

    int byteReceived = 0;
    while (true)
    {
        char buffer[1024];  // 1kb

        if((byteReceived += recv(hsock, buffer, sizeof(buffer), 0))== -1) 
        {
            std::cout << "Error receiving data, error code : " << errno << std::endl;
        } else if (byteReceived == 0) {
            break;
        }

        std::cout << "Total byte count received is " << byteReceived << std::endl;
        OnNewMessage(buffer);
    }

    close(hsock);
}
