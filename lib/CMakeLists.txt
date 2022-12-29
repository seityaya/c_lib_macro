#Author                 : Seityagiya Terlekchi
#Contacts               : seityaya@ukr.net
#Creation Date          : 2020.05
#License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
#SPDX-License-Identifier: LGPL-2.1-or-later
#Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
add_definitions(-std=c11)

set(VERSION 0.1)
set(PROJECT_NAME yaya_defines)

project(${PROJECT_NAME})

set(SRC_LIST yaya_defines.c)
set(INC_LIST
    yaya_defines.h
    yaya_bool.h
    yaya_unused.h)

add_library(${PROJECT_NAME} SHARED ${SRC_LIST} ${INC_LIST})
