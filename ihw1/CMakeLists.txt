cmake_minimum_required(VERSION 3.25)

project(sorting)

add_library(sorts STATIC
    sorts/selectionSort.cpp
    sorts/bubbleSort.cpp
    sorts/insertSort.cpp
    sorts/countSort.cpp
    sorts/radixSort.cpp
)

add_executable(main main.cpp)

target_link_libraries(main sorts)
