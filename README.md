## Flatbuffers Cpp Demo
This project is built base on Flatbuffers. So 
- Please install flatbuffers compiler([flatc](https://google.github.io/flatbuffers/flatbuffers_guide_using_schema_compiler.html)) on your local enviroment.
- Please download [Flatbuffers](https://github.com/google/flatbuffers) and put it under `ThirdParty` folder. 

Then I believe you can build on your local environment. Also you can find the compiled files under `build` folder. I run it on MacOs. Please contact me if it is not able to be run on Linux.

## Compile flatbuffers file
Firstly, please compile your `.fbs` file to generate header file.
```shell
cd datamodel
./gen
```
then `marketdata_generated.h` file will be generated.

## Compile your project
Make sure you have install flatbuffers on your local environment
```shell
mkdir build
cd build
cmake ..
cmake --build .
```

## Run the server
```shell
cd build/Server
./server
```

## Run the client
```shell
cd build/Client
./client
```
