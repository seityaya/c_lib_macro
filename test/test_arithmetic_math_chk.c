//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.03
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "test.h"
#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_math_chk) {
    UT_GROUP_BEG(math) {
        is8_t  r_i = 0;
        us8_t  r_s = 0;

        int k = 0;
        UT_GROUP_BEG(sum_chk) {
            k = 0;
            for(int i = -128; i <= 127; i++){
                for(int j = -128; j <= 127; j++){
                    bool_t flag = false;

                    int res = i + j;
                    if((res < -128) || (res > 127)){
                        flag = true;
                    }

                    is8_t a = (is8_t)(i);
                    is8_t b = (is8_t)(j);
                    is8_t r;

                    if(flag != sum_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    int res = i + j;
                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    us8_t r;

                    if(flag != sum_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(   0), i8_c( 127))); UT_ASSERT_NUM_EQ(i8_c( 127), r_i);
            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(   0), i8_c(-128))); UT_ASSERT_NUM_EQ(i8_c(-128), r_i);

            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c( 127), i8_c(   0))); UT_ASSERT_NUM_EQ(i8_c( 127), r_i);
            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(-128), i8_c(   0))); UT_ASSERT_NUM_EQ(i8_c(-128), r_i);

            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(   1), i8_c(   1))); UT_ASSERT_NUM_EQ(i8_c(   2), r_i);
            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(  -1), i8_c(   1))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(   1), i8_c(  -1))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_FL(sum_chk(r_i, i8_c(  -1), i8_c(  -1))); UT_ASSERT_NUM_EQ(i8_c(  -2), r_i);

            UT_ASSERT_BOOL_TR (sum_chk(r_i, i8_c(   1), i8_c( 127))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_TR (sum_chk(r_i, i8_c(  -1), i8_c(-128))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);

            UT_ASSERT_BOOL_FL(sum_chk(r_s, u8_c(   1), u8_c(   1))); UT_ASSERT_NUM_EQ(u8_c(   2), r_s);
            UT_ASSERT_BOOL_FL(sum_chk(r_s, u8_c(   0), u8_c( 255))); UT_ASSERT_NUM_EQ(u8_c( 255), r_s);
            UT_ASSERT_BOOL_TR (sum_chk(r_s, u8_c(   1), u8_c( 255))); UT_ASSERT_NUM_EQ(u8_c(   0), r_s);
        } UT_GROUP_END;

        UT_GROUP_BEG(dif_chk) {
            k = 0;
            for(int i = -128; i <= 127; i++){
                for(int j = -128; j <= 127; j++){
                    bool_t flag = false;

                    int res = i - j;
                    if((res < -128) || (res > 127)){
                        flag = true;
                    }

                    is8_t a = (is8_t)(i);
                    is8_t b = (is8_t)(j);
                    is8_t r;

                    if(flag != dif_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }

                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    int res = i - j;
                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    us8_t r;

                    if(flag != dif_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(   0), i8_c( 127))); UT_ASSERT_NUM_EQ(i8_c(-127), r_i);
            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c( 127), i8_c(   0))); UT_ASSERT_NUM_EQ(i8_c( 127), r_i);

            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(-128), i8_c(   0))); UT_ASSERT_NUM_EQ(i8_c(-128), r_i);

            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(   1), i8_c(   1))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(  -1), i8_c(   1))); UT_ASSERT_NUM_EQ(i8_c(  -2), r_i);
            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(   1), i8_c(  -1))); UT_ASSERT_NUM_EQ(i8_c(  +2), r_i);
            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(  -1), i8_c(  -1))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);

            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(  -1), i8_c( 127))); UT_ASSERT_NUM_EQ(i8_c(-128), r_i);
            UT_ASSERT_BOOL_FL(dif_chk(r_i, i8_c(  -1), i8_c(-128))); UT_ASSERT_NUM_EQ(i8_c( 127), r_i);

            UT_ASSERT_BOOL_TR (dif_chk(r_i, i8_c(   0), i8_c(-128))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_TR (dif_chk(r_i, i8_c(-128), i8_c(   1))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_TR (dif_chk(r_i, i8_c(   1), i8_c(-128))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);
            UT_ASSERT_BOOL_TR (dif_chk(r_i, i8_c( 127), i8_c(  -1))); UT_ASSERT_NUM_EQ(i8_c(   0), r_i);

            UT_ASSERT_BOOL_FL(dif_chk(r_s, u8_c(   1), u8_c(   1))); UT_ASSERT_NUM_EQ(u8_c(   0), r_s);
            UT_ASSERT_BOOL_TR (dif_chk(r_s, u8_c(   0), u8_c(   1))); UT_ASSERT_NUM_EQ(u8_c(   0), r_s);
            UT_ASSERT_BOOL_TR (dif_chk(r_s, u8_c(   1), u8_c( 255))); UT_ASSERT_NUM_EQ(u8_c(   0), r_s);
        } UT_GROUP_END;

        UT_GROUP_BEG(mul_chk) {
            k = 0;
            for(int i = -128; i <= 127; i++){
                for(int j = -128; j <= 127; j++){
                    bool_t flag = false;

                    int res = i * j;
                    if((res < -128) || (res > 127)){
                        flag = true;
                    }

                    is8_t a = (is8_t)(i);
                    is8_t b = (is8_t)(j);
                    is8_t r;

                    if(flag != mul_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    int res = i * j;
                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    us8_t r;

                    if(flag != mul_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);
        } UT_GROUP_END;

        UT_GROUP_BEG(div_chk) {
            k = 0;
            for(int i = -128; i <= 127; i++){
                for(int j = -128; j <= 127; j++){
                    bool_t flag = false;

                    int res =  0;
                    if(j != 0){
                        res = i / j;
                    }else{
                        flag = true;
                    }

                    if((res < -128) || (res > 127)){
                        flag = true;
                    }

                    is8_t a = (is8_t)(i);
                    is8_t b = (is8_t)(j);
                    is8_t r;

                    if(flag != div_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    int res =  0;
                    if(j != 0){
                        res = i / j;
                    }else{
                        flag = true;
                    }

                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    us8_t r;

                    if(flag != div_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);
        } UT_GROUP_END;

        UT_GROUP_BEG(mod_chk) {
            k = 0;
            for(int i = -128; i <= 127; i++){
                for(int j = -128; j <= 127; j++){
                    bool_t flag = false;

                    int res =  0;
                    if(j != 0){
                        res = i % j;
                    }else{
                        flag = true;
                    }

                    if((res < -128) || (res > 127)){
                        flag = true;
                    }

                    is8_t a = (is8_t)(i);
                    is8_t b = (is8_t)(j);
                    is8_t r;

                    if(flag != mod_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    int res =  0;
                    if(j != 0){
                        res = i % j;
                    }else{
                        flag = true;
                    }

                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    us8_t r;

                    if(flag != mod_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);
        } UT_GROUP_END;

        UT_GROUP_BEG(qut_chk) {
            k = 0;
            for(int i = -128; i <= 127; i++){
                for(int j = -128; j <= 127; j++){
                    bool_t flag = false;

                    int res =  0;
                    if(j != 0){
                        res = (int)qut(i, j);
                    }else{
                        flag = true;
                    }

                    if((res < -128) || (res > 127)){
                        flag = true;
                    }

                    is8_t a = (is8_t)(i);
                    is8_t b = (is8_t)(j);
                    is8_t r;

                    if(flag != qut_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    int res =  0;
                    if(j != 0){
                        res = (int)qut(i, j);
                    }else{
                        flag = true;
                    }

                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    us8_t r;

                    if(flag != qut_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);

            k = 0;
            for(int i = 0; i <= 255; i++){
                for(int j = 0; j <= 255; j++){
                    bool_t flag = false;

                    fmax_t res =  0;
                    if(j != 0){
                        res = qut(i, j);
                    }else{
                        flag = true;
                    }

                    if((res < 0) || (res > 255)){
                        flag = true;
                    }

                    us8_t a = (us8_t)(i);
                    us8_t b = (us8_t)(j);
                    fmax_t r;

                    if(flag != qut_chk(r, a, b)){
                        k++;
                    }

                    if(!flag && res != r){
                        k++;
                    }
                }
            }
            UT_ASSERT_NUM_EQ(k, 0);
        } UT_GROUP_END;

        UT_GROUP_BEG(powm_chk) {

        } UT_GROUP_END;

        UT_GROUP_BEG(root_chk) {

        } UT_GROUP_END;

        UT_GROUP_BEG(logm_chk) {

        } UT_GROUP_END;

        UT_GROUP_BEG(abs_chk) {

        } UT_GROUP_END;
    } UT_GROUP_END;
}
