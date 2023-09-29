#Author                 : Seityagiya Terlekchi
#Contacts               : seityaya@ukr.net
#Creation Date          : 2020.05
#License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
#SPDX-License-Identifier: LGPL-2.1-or-later
#Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
add_definitions(-std=c11)

set(VERSION 0.1)
set(PROJECT_NAME define_test)
project(${PROJECT_NAME})

add_compile_options(-Wall -Wfatal-errors -Wconversion -Warith-conversion -Wfloat-conversion -Wsign-conversion -Wenum-conversion)

file(GLOB FILES
    *.c
    *.h
    test_arithmetic/*.c
    test_bit/*.c
)

add_executable(
    ${PROJECT_NAME}
    ${FILES}
)

if (NOT TARGET yaya_unit)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../../yaya_unit/lib/ yaya_unit)
    target_include_directories(${PROJECT_NAME} PRIVATE ../../yaya_unit/lib/)
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC yaya_unit)

if (NOT TARGET yaya_define)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../lib/ yaya_define)
    target_include_directories(${PROJECT_NAME} PRIVATE ../lib/)
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC yaya_define)
