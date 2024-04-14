cmake_minimum_required(VERSION 3.27)
project(lwbop C)

set(CMAKE_C_STANDARD 11)

add_executable(lwbop main.c
        libs/data_structures/vector/vector.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/voidVector.h
        libs/data_structures/vector/voidVector.c
        libs/data_structures/vector/testVector.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/testMatrix.c
        libs/data_structures/matrix/testMatrix.h
        libs/data_structures/matrix/tasks/matrixTasks.c
        libs/data_structures/matrix/tasks/matrixTasks.h
        libs/data_structures/matrix/tasks/testMatrixTasks.h
        libs/data_structures/matrix/tasks/testMatrixTasks.c
)