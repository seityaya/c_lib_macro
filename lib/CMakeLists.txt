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
set(PROJECT_NAME yaya_defines)

project(${PROJECT_NAME})

set(SRC_LIST
    yaya_bit.c
    yaya_debug.c)

set(INC_LIST
    yaya_arithmetic.h
    yaya_bit.h
    yaya_bit.c
    yaya_defines.h
    yaya_bool.h
    yaya_unused.h
    yaya_sugar.h
    yaya_concat.h
    yaya_endian.h
    yaya_flag.h
    yaya_type.h
    yaya_number.h
    yaya_debug.h
    yaya_chek.h)

add_library(${PROJECT_NAME} SHARED ${SRC_LIST} ${INC_LIST})

target_link_libraries(${PROJECT_NAME} m)
