//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.01
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "stdio.h"

#include "test.h"
#include "yaya_sugar.h"

UT_FUNC_GEN(test_sugar) {
    UT_GROUP_BEG(sugar) {

        printf("1:\n"); fflush(stdout);
        int i = 0;
        printf("1.1/3 beg i = %d\n", i); fflush(stdout);
        beg {
            i++;
            if(i == 1){
                printf("1.2/3 con i = %d\n", i); fflush(stdout);
                continue;
            }

            if(i == 2){
                printf("1.3/3 bre i = %d\n", i); fflush(stdout);
                break;
            }

            i++;
            printf("error end i = %d\n", i); fflush(stdout);
        } end;

        printf("2:\n"); fflush(stdout);
        i = 0;
        printf("2.1/3 beg i = %d\n", i); fflush(stdout);
        beg {
            i++;
            if(i == 1){
                printf("2.2/3 con i = %d\n", i); fflush(stdout);
                continue;
            }

            i++;
            if(i == 2){
                printf("error bre i = %d\n", i); fflush(stdout);
                break;
            }

            i++;
            printf("2.3/3 end i = %d\n", i); fflush(stdout);
        } end;

        printf("3:\n"); fflush(stdout);
        if(true)
            beg {
                printf("3.1/1 if block \n");
            } end;
    } UT_GROUP_END;
}
