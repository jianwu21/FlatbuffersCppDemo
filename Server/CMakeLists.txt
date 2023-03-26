project ("server")
set(CMAKE_CXX_STANDARD 17)

include_directories(../datamodel/)

if (NOT TARGET flatbuffers)
    add_subdirectory(
    ../ThirdParty/flatbuffers
    ${CMAKE_CURRENT_BINARY_DIR}/flatbuffers-build
    EXCLUDE_FROM_ALL)
endif()

file(GLOB source_files *.cpp)
set(SOURCES ${source_files})

file(GLOB header_files *.h)
set(HEADERS ${header_files})

# Add source to this project's executable.
add_executable (
    server 
    ${SOURCES} 
    ${HEADERS}
    "../datamodel/marketdata_generated.h"
)
target_link_libraries(server PRIVATE flatbuffers)
