cmake_minimum_required(VERSION 3.6)
project(edge)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MorphoFeatures.cpp MorphoFeatures.h)
add_executable(edge ${SOURCE_FILES})
target_link_libraries(edge ${OpenCV_LIBS})