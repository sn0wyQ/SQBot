cmake_minimum_required(VERSION 3.19)
project(SQBot_example)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
        "$<$<CONFIG:RELEASE>:-O3>"
        "$<$<CONFIG:DEBUG>:-O0>"
)

# libcurl
find_package(CURL REQUIRED)

set(SOURCES
        include/SQBot/Bot/bot.cpp
        include/SQBot/Message/message.cpp
        include/SQBot/User/user.cpp
        include/SQBot/Utils/utils.h
        )

set(LIBS
        ${CURL_LIBRARY})

add_executable(SQBot_example example.cpp ${SOURCES})
target_link_libraries(SQBot_example ${LIBS})

target_include_directories(SQBot_example PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/SQBot>
        $<INSTALL_INTERFACE:include/SQBot>
        )
target_include_directories(SQBot_example PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/nlohmann>
        $<INSTALL_INTERFACE:include/nlohmann>
        )
include_directories(${CURL_INCLUDE_DIR})
