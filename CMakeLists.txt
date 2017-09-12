cmake_minimum_required(VERSION 3.8)
project(translator)

set(CMAKE_CXX_STANDARD 14)

file(GLOB CPPS "src/*.cpp")
file(GLOB HS "src/*.h")


add_executable(${PROJECT_NAME} ${CPPS} ${HS})