cmake_minimum_required(VERSION 3.19)
project(SQBot_example)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
        "$<$<CONFIG:RELEASE>:-O3>"
        "$<$<CONFIG:DEBUG>:-O0>"
)

# libcurl
if (WIN32)
    set(CURL_LIBRARY "C:/curl/lib/libcurl.a")
    set(CURL_INCLUDE_DIR "C:/curl/include/curl")
endif()
find_package(CURL REQUIRED)
add_definitions(-DCURL_STATICLIB)

set(SOURCES
        include/SQBot/Bot/bot.cpp
        include/SQBot/Message/message.cpp)

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
