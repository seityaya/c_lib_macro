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
set(PROJECT_NAME defines_test)
project(${PROJECT_NAME})

add_executable(
    ${PROJECT_NAME}
    main.c
    test.h
    test_arithmetic_constant.c
    test_arithmetic_unar.c
    test_arithmetic_assignment.c
    test_arithmetic_segment.c
    test_arithmetic_math.c
    test_arithmetic_math_chk.c
    test_arithmetic_decomposition.c
    test_arithmetic_iter.c
    test_arithmetic_compare.c
    test_arithmetic_parity.c
    test_arithmetic_round.c
    test_arithmetic_minmax.c
    test_arithmetic_progresion.c
    test_arithmetic_series.c
    test_arithmetic_combinatoric.c
    test_bit.c
    test_bool.c
    test_debug.c
    test_rand.c
    test_sugar.c
)

if (NOT TARGET yaya_unit)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../../yaya_unit/lib/ yaya_unit)
    target_include_directories(${PROJECT_NAME} PUBLIC ../../yaya_unit/lib/)
    target_link_libraries(${PROJECT_NAME} yaya_unit)
endif()


if (NOT TARGET yaya_defines)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../lib/ yaya_defines)
    target_include_directories(${PROJECT_NAME} PUBLIC ../lib/)
    target_link_libraries(${PROJECT_NAME} yaya_defines)
endif()

