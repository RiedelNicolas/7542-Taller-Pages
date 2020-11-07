cmake_minimum_required(VERSION 3.17)
project(7542_Taller_Pages)

set(CMAKE_CXX_STANDARD 14)

file(GLOB common_src
        "*.h"
        "*.cpp"
        )

file(GLOB server_src
        "*.h"
        "*.cpp"
        )

file(GLOB client_src
        "*.h"
        "*.cpp"
        )

add_executable(client client_src ${client_src} ${common_src} )

add_executable(server server_src ${client_src} ${server_src} )


target_compile_options (client PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline)

target_link_options(client PRIVATE -lm)

target_compile_options (server PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline)

target_link_options(server PRIVATE -lm)