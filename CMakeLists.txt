cmake_minimum_required(VERSION 3.17)
project(7542_Taller_Pages)

set(CMAKE_CXX_STANDARD 14)

set(COMMON common_src/OSexception.cpp common_src/OSexception.h common_src/Socket.cpp common_src/Socket.h common_src/SocketException.cpp
            common_src/Socket.h)


add_executable(client ${COMMON} client_src/main.cpp  )

add_executable(server ${COMMON}  server_src/main.cpp )


target_compile_options (client PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline)

target_link_options(client PRIVATE -lm)

target_compile_options (server PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline)

target_link_options(server PRIVATE -lm)