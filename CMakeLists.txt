cmake_minimum_required(VERSION 3.17)
project(7542_Taller_Pages)

set(CMAKE_CXX_STANDARD 14)

set(COMMON common_src/OSexception.cpp common_src/OSexception.h common_src/Socket.cpp common_src/Socket.h common_src/SocketException.cpp
            common_src/Socket.h common_src/Thread.cpp common_src/Thread.h common_src/Lock.cpp common_src/Lock.h common_src/InvalidFileException.cpp common_src/InvalidFileException.h)


add_executable(client ${COMMON} client_src/main.cpp client_src/Client.cpp client_src/Client.h )

add_executable(server ${COMMON}  server_src/main.cpp server_src/Server.cpp server_src/Server.h server_src/ClientHandler.cpp server_src/ClientHandler.h server_src/RequestsManager.cpp server_src/RequestsManager.h server_src/PetitionParser.cpp server_src/PetitionParser.h server_src/PrintMonitor.cpp server_src/PrintMonitor.h server_src/ResourcesRepository.cpp server_src/ResourcesRepository.h server_src/PetitionProcessor.cpp server_src/PetitionProcessor.h server_src/PetitionLogic.cpp server_src/PetitionLogic.h server_src/PetitionPost.cpp server_src/PetitionPost.h server_src/PetitionGet.cpp server_src/PetitionGet.h server_src/PetitionInvalid.cpp server_src/PetitionInvalid.h)


target_compile_options (client PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline -Werror=sign-compare )

target_link_options(client PRIVATE -lm -pthread)

target_compile_options (server PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline -Werror=sign-compare )

target_link_options(server PRIVATE -lm -pthread)