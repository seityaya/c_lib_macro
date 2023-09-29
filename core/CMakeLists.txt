## Author                 : Seityagiya Terlekchi
## Contacts               : seityaya@ukr.net
## Last Update Date       : 2024
## License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
## SPDX-License-Identifier: LGPL-2.1-or-later
## Copyright © Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 11)
add_definitions(-std=c11)

set(VERSION 0.1)
set(PROJECT_NAME yaya_define)
project(${PROJECT_NAME})

add_compile_options(-Wall -Wfatal-errors -Wconversion -Warith-conversion -Wfloat-conversion -Wsign-conversion -Wenum-conversion)

file(GLOB FILES
    *.c
    *.h
)

set(SOURSE_LIST                        #decor    #impl     #test
    yaya_argcount.h                    #100%     #100%     #100%
    yaya_arithmetic_constant.h         #100%     #100%     #----
    yaya_arithmetic_discrete.h         #         #         #
    yaya_arithmetic_round.h            #         #         #
    yaya_arithmetic.c                  #         #         #
    yaya_arithmetic.h                  #100%     #         #
    yaya_bit.c                         #100%     #100%     #100%
    yaya_bit.h                         #100%     #100%     #100%
    yaya_bool.h                        #100%     #100%     #100%
    yaya_cdecl.h                       #100%     #100%     #----
    yaya_check.h                       #100%     #100%     #100%
    yaya_concat.h                      #100%     #100%     #100%
    yaya_debug.c                       #100%     #100%     #100%
    yaya_debug.h                       #100%     #100%     #100%
    yaya_endian.h                      #100%     #100%     #100%
    yaya_flag.h                        #100%     #         #
    yaya_gover.h                       #100%     #100%     #----
    yaya_rand.c                        #         #         #
    yaya_rand.h                        #         #         #
    yaya_sugar.h                       #100%     #100%     # 50%
    yaya_type.h                        #100%     #100%     #100%
    yaya_unused.h                      #100%     #100%     #100%

    ${FILES}
)

add_library(${PROJECT_NAME} ${SOURSE_LIST})

target_link_libraries(${PROJECT_NAME} m)
