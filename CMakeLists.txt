cmake_minimum_required(VERSION 3.4)
project(booman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wno-multichar -static-libgcc -static-libstdc++ ")

set(SOURCE_FILES main.cpp booman.cpp booman.h booTokenizer.cpp booTokenizer.h booConst.h ocBuffer.cpp ocBuffer.h booRPNParser.cpp booRPNParser.h booBoolExpression.cpp booBoolExpression.h booTypes.h booTokenSerializer.cpp booTokenSerializer.h)
set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR}/bin
)
#add_library(booman SHARED booDllExport.cpp booDllExport.h)

add_library(booman_lib SHARED ${SOURCE_FILES} booDllExport.cpp booDllExport.h)

add_executable(booman_test ${SOURCE_FILES} booDllExport.h)
target_link_libraries(booman_test booman_lib)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

