cmake_minimum_required(VERSION 3.25)

project(subs)

add_library(perf STATIC
    perf/perf.cpp
    perf/gen.cpp
)

add_library(algo STATIC
    algo/simple.cpp
    algo/kmp.cpp
    algo/cooler_kmp.cpp)

add_executable(main
    main.cpp
)

target_link_libraries(main perf algo)