#Author                 : Seityagiya Terlekchi
#Contacts               : terlekchiseityaya@gmail.com
#Creation Date          : 2020.05
#License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
#SPDX-License-Identifier: LGPL-2.1-or-later
#Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)

project(
    yaya_macro
    VERSION      0.1.0.0
    LANGUAGES    C
    HOMEPAGE_URL "https://github.com/seityaya/c_lib_macro"
    DESCRIPTION  "All macro in one project"
)

set(CMAKE_C_STANDARD 23)

file(GLOB FILES *.c *.h)

set(SOURSE_LIST ${FILES})

add_library(${PROJECT_NAME} ${SOURSE_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
