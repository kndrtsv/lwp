cmake_minimum_required(VERSION 3.27)
project(lwbop C)

set(CMAKE_C_STANDARD 11)

add_executable(lwbop main.c
        libs/data_structures/vector/vector.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/voidVector.h
        libs/data_structures/vector/voidVector.c)
