cmake_minimum_required(VERSION 3.20)

project(OmegaFish)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OmegaFish
    tests/testrook.cpp
    src/bitboards/bitboards.cpp
)

target_include_directories(OmegaFish PRIVATE
    include
)