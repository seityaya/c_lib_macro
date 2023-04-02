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
        UT_SPASE_TEST_BEG{
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
        } UT_SPASE_TEST_END;
    } UT_GROUP_END;

    UT_GROUP_BEG(value_address) {
        init_val(A, int);
        init_val(B, char);
        UT_ASSERT_NUM_EQ(0, A);
        UT_ASSERT_CHR_EQ(char_c('0'), B);

        init_ptr(a, int);
        init_ptr(b, char);
        //        UT_ASSERT_TYPE_EQ((int*), a);
        //        UT_ASSERT_TYPE_EQ((char*), b);
        UT_ASSERT_NUL_EQ(a);
        UT_ASSERT_NUL_EQ(b);

        crete_val(i, 1.0);
        UT_ASSERT_FLT_EQ(1.0, i);
        UT_ASSERT_TYP_EQ( (double){0}, i);

        crete_ptr(p, i);
        UT_ASSERT_PTR_EQ(p, &i);
        UT_ASSERT_TYP_EQ( (double*){0}, p);
    } UT_GROUP_END;
}
