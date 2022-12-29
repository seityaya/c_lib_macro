//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2020.05
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2020-2022 Seityagiya Terlekchi. All rights reserved.


#ifndef YAYA_DEFINES_H_
#define YAYA_DEFINES_H_

/*
 * Библиотека полезных определений для использования и отладки программ
*/

/*==================================================================================================================*/
/*LIBRARIES*/
#include "yaya_bool.h"
#include "yaya_unused.h"

#include "inttypes.h"
#include "stdlib.h"
#include "time.h"
#include "limits.h"
#include "stdint.h"
#include "stdio.h"

/*==================================================================================================================*/
/*CONCATENATE*/
#define MACRODELAY(x) x
#define CAT_3(x, y) CAT_2(MACRODELAY(x), MACRODELAY(y))
#define CAT_2(x, y) CAT_1(x, y)
#define CAT_1(x, y) x##y

/*==================================================================================================================*/
/*SUGAR*/
#define ever      (;;)
#define forever() for ever
#define ternarius(_if, _true, _false) ((_if) ? (_true) ? (_false))

/*
 * Новый тип блока в котором разрешено использовать break и continue вместо
 * конструкции do{ }while (false) или while (true){ }, (где, кстати невозможно
 * использовать оператор continue, без явного указания break, а тут он встроен)
 * и это выглядит опрятнее и намного опаснее в использовании т.к. continue выполняет
 * роль прыжка в начало блока и повтора всех действий. Хехе.
 * Расширяет возможности по управлению ходом выполнения программы без
 * использования оператора goto, если они запрещены явно, для перехода в конец.
 * Можно использовать как с фигурными скобками так и без.
 * Можно использовать с другими операторами if/else, switch/case вместо скобок.
 */

#define beg do{
#define end break; } while (true)

/*==================================================================================================================*/
/*BIT*/
/*В данных операциях биты нумеруются с 1, если указан 0, то изменений не происходит
 *Если функция возвращает результат, то он тоже нумерует биты от 1
*/

#define BIT_BEG(x)  BIT_POS(((x) & -(x)))  //вернуть позицию первого взведенного бита
#define BIT_END(x)  BIT_POS(x)             //вернуть позицию последнего взведенного бита
#define BIT_NUM(x)  yaya_bit_onse_bit(x)   //подсчитать количество взведеных битов
#define BIT_POS(x)  yaya_bit_position(x)   //вернуть позицию одного единичного бита, если битов несколько, то -1

#define BIT_GET(x, n)    ((n) == 0 ? (0) : ((x) &  (1ULL << ((n) - 1))))      //чтение бита на позии
#define BIT_SET(x, n)    ((n) == 0 ? (x) : ((x) |  (1ULL << ((n) - 1))))      //выставление бита  на позии
#define BIT_RES(x, n)    ((n) == 0 ? (x) : ((x) & ~(1ULL << ((n) - 1))))      //сброс бита на позии
#define BIT_TOG(x, n)    ((n) == 0 ? (x) : ((x) ^  (1ULL << ((n) - 1))))      //переключение бита на позиции
#define BIT_WRT(x, n, v) ((v) ? BIT_SET((x), (n)) : BIT_RES((x), (n)))        //выставление определенного бита на позии
#define BIT_REV(x)       yaya_bit_revers((x), sizeof(x))                      //смена порядка битов то начала к концу

#define BIT_SHF_RIG(x, n) ( (x) >> (n))                                                  //сбвиг вправо c занулением ??
#define BIT_SHF_LFT(x, n) ( (x) << (n))                                                  //сдвиг влево с занулением  ??
#define BIT_SHF_VEC(x, n) (((n) < (0)) ? BIT_SHF_RIG((x), -(n)) : BIT_SHF_LFT((x), (n))) //сдвиг относительно знака числа, + влево, - вправо

#define BIT_CYC_RIG(x, n) ( (n) == 0 ? (x) : ((x) >> (n)) | ((x) << ((sizeof(x)*8) - (n))))     //циклический сдвиг вправо
#define BIT_CYC_LEF(x, n) ( (n) == 0 ? (x) : ((x) << (n)) | ((x) >> ((sizeof(x)*8) - (n))))     //циклический сдвиг влево
#define BIT_CYC_VEC(x, n) (((n) < (0)) ? BIT_CYC_RIG((x), -(n)) : BIT_CYC_LEF((x), (n)))        //сдвиг относительно знака числа, + влево, - вправо

#define BIT_MASK_IN(x)    (~(x))                                              //инвертирование всех битов
#define BIT_MASK_UP(x, y) ((x) | (y))                                         //выставление битов по еденичной маске
#define BIT_MASK_DW(x, y) ((x) & (y))                                         //обнуление битов по еденичной маске

/*==================================================================================================================*/
/*ENDIANNESS*/
#define ENDIAN_BIT (((union { unsigned x; unsigned char c; }){1}).c)       //типа архитектуры
#define ENDIAN_BIG 0
#define ENDIAN_LIT 1

/*==================================================================================================================*/
/*FLAG*/
#define FLAG_SET(x)    (((x) == 0) ? (0ULL) : (1ULL << ((x) - 1ULL)))  //установка флага
#define FLAG_COM(x, y) ((x) & (y))                                     //сравнение двух или масок
#define FLAG_ALL       (((0ULL) - 1))                                  //выставление всех флагов
#define FLAG_NUL       (0)                                             //сброс всех флагов

/*==================================================================================================================*/
/*FLAG*/
#define POSITIV(a) (a) > 0 ? (a) : (-(a))
#define NEGITIV(a) (a) < 0 ? (a) : (-(a))

/*==================================================================================================================*/
/*LOGICAL*/
//16 операций



/*========================================================================================*/
/*GENERIC FUNCTION*/
#define typename(x) _Generic((x),                         \
    char:                       "char",                   \
    signed char:                "signed char",            \
    unsigned char:              "unsigned char",          \
    signed int:                 "signed int",             \
    unsigned int:               "unsigned int",           \
    signed short:               "signed short",           \
    unsigned short:             "unsigned short",         \
    signed long:                "signed long",            \
    unsigned long:              "unsigned long",          \
    signed long long:           "signed long long",       \
    unsigned long long:         "unsigned long long",     \
    \
    float:                      "float",                  \
    \
    double:                     "double",                 \
    long double:                "long double",            \
    \
    char*:                      "point to char",                   \
    signed char*:               "point to signed char",            \
    unsigned char*:             "point to unsigned char",          \
    signed int*:                "point to signed int",             \
    unsigned int*:              "point to unsigned int",           \
    signed short*:              "point to signed short",           \
    unsigned short*:            "point to unsigned short",         \
    signed long*:               "point to signed long",            \
    unsigned long*:             "point to unsigned long",          \
    signed long long*:          "point to signed long long",       \
    unsigned long long*:        "point to unsigned long long",     \
    \
    float*:                     "point to float",                  \
    \
    double*:                    "point to double",                 \
    long double*:               "point to long double",            \
    \
    default:                    "other")

#define TYPE_NAN   0
#define TYPE_CHR   1
#define TYPE_INT   2
#define TYPE_FLT   3
#define TYPE_CHR_P 4
#define TYPE_INT_P 5
#define TYPE_FLT_P 6

#define typeid(x) _Generic((x),      \
    char:                       TYPE_CHR,   \
    signed char:                TYPE_INT,   \
    unsigned char:              TYPE_INT,   \
    signed int:                 TYPE_INT,   \
    unsigned int:               TYPE_INT,   \
    signed short:               TYPE_INT,   \
    unsigned short:             TYPE_INT,   \
    signed long:                TYPE_INT,   \
    unsigned long:              TYPE_INT,   \
    signed long long:           TYPE_INT,   \
    unsigned long long:         TYPE_INT,   \
    \
    float:                      TYPE_FLT,   \
    double:                     TYPE_FLT,   \
    long double:                TYPE_FLT,   \
    \
    char*:                      TYPE_CHR_P,   \
    signed char*:               TYPE_INT_P,   \
    unsigned char*:             TYPE_INT_P,   \
    signed int*:                TYPE_INT_P,   \
    unsigned int*:              TYPE_INT_P,   \
    signed short*:              TYPE_INT_P,   \
    unsigned short*:            TYPE_INT_P,   \
    signed long*:               TYPE_INT_P,   \
    unsigned long*:             TYPE_INT_P,   \
    signed long long*:          TYPE_INT_P,   \
    unsigned long long*:        TYPE_INT_P,   \
    \
    float*:                     TYPE_FLT_P,   \
    double*:                    TYPE_FLT_P,   \
    long double*:               TYPE_FLT_P,   \
    \
    default:                    TYPE_NAN)

#define typespec(x) _Generic((x),                         \
    char:                       "chr",                    \
    int8_t:                     "i08",                    \
    int16_t:                    "i16",                    \
    int32_t:                    "i32",                    \
    int64_t:                    "i64",                    \
    uint8_t:                    "u08",                    \
    uint16_t:                   "u16",                    \
    uint32_t:                   "u32",                    \
    uint64_t:                   "u64",                    \
    float:                      "flt",                    \
    double:                     "dbl",                    \
    \
    char*:                      "chr",                    \
    int8_t*:                    "i08",                    \
    int16_t*:                   "i16",                    \
    int32_t*:                   "i32",                    \
    int64_t*:                   "i64",                    \
    uint8_t*:                   "u08",                    \
    uint16_t*:                  "u16",                    \
    uint32_t*:                  "u32",                    \
    uint64_t*:                  "u64",                    \
    float*:                     "flt",                    \
    double*:                    "dbl",                    \
    \
    default:                    "nan")

#define typeprint(x) _Generic((x),                        \
    char:                       "%"PRIi8,                 \
    int8_t:                     "%"PRIi8,                 \
    int16_t:                    "%"PRIi16,                \
    int32_t:                    "%"PRIi32,                \
    int64_t:                    "%"PRIi64,                \
    uint8_t:                    "%"PRIu8,                 \
    uint16_t:                   "%"PRIu16,                \
    uint32_t:                   "%"PRIu32,                \
    uint64_t:                   "%"PRIu64,                \
    \
    float:                      "%""f",                   \
    double:                     "%""f",                   \
    \
    char*:                      "chr",                    \
    int8_t*:                    "i08",                    \
    int16_t*:                   "i16",                    \
    int32_t*:                   "i32",                    \
    int64_t*:                   "i64",                    \
    uint8_t*:                   "u08",                    \
    uint16_t*:                  "u16",                    \
    uint32_t*:                  "u32",                    \
    uint64_t*:                  "u64",                    \
    float*:                     "flt",                    \
    double*:                    "dbl",                    \
    \
    default:                    "nan")

/*========================================================================================*/
/*DEBUG FUNCTION*/
#define PRINT_LOC_MAIN(x)    printf("%s : %d\n", __FILE__, __LINE__)
#define PRINT_FNC_MAIN(x)    printf("%s : %d\n", __func__, __LINE__)
#define PRINT_BIT_MAIN(x)    yaya_print_bit(&(x), sizeof(x))
#define PRINT_RAW_MAIN(x)    yaya_print_raw(&(x), sizeof(x))
#define PRINT_TXT_MAIN(x)    printf(#x); PRINT_NLN()

#define PRINT_SIZ_MAIN(x)    printf("%" PRIuPTR " * %" PRIuMAX "bit\n", sizeof(x), (umax)CHAR_BIT)
#define PRINT_TYP_MAIN(x)    printf("%s\n", typename(x))

#define PRINT_INT_MAIN(x)    printf(typeprint(x), x); PRINT_NLN()
#define PRINT_CHR_MAIN(x)    printf("\'%c\'\n", x)
#define PRINT_FLT_MAIN(x)    printf("%.60f\n", (flmxn(x)))
#define PRINT_STR_MAIN(x)    printf("\'%s\'\n", (TYPE_CHR == typeid(x)) ? (char*)(x) : "[not a text string]")
#define PRINT_PTR_MAIN(x)    printf("%p\n", (&x))


#define PRINT_LOC_TYPE(x)    printf("[loc] " #x " = ")
#define PRINT_FNC_TYPE(x)    printf("[fnk] " #x " = ")
#define PRINT_BIT_TYPE(x)    printf("[bit] " #x " = ")
#define PRINT_RAW_TYPE(x)    printf("[raw] " #x " = ")
#define PRINT_TXT_TYPE(x)    printf("[txt] " #x " = ")
#define PRINT_INT_TYPE(x)    printf("[%3s] " #x " = ", typespec(x))
#define PRINT_CHR_TYPE(x)    printf("[chr] " #x " = ")
#define PRINT_SIZ_TYPE(x)    printf("[siz] " #x " = ")
#define PRINT_TYP_TYPE(x)    printf("[typ] " #x " = ")
#define PRINT_FLT_TYPE(x)    printf("[flt] " #x " = ")
#define PRINT_STR_TYPE(x)    printf("[str] " #x " = ")
#define PRINT_PTR_TYPE(x)    printf("[ptr] " #x " = ")


#define PRINT_LOC(x)    PRINT_LOC_TYPE(x); PRINT_LOC_MAIN(x)
#define PRINT_FNC(x)    PRINT_FNC_TYPE(x); PRINT_FNC_MAIN(x)
#define PRINT_INT(x)    PRINT_INT_TYPE(x); PRINT_INT_MAIN(x)
#define PRINT_CHR(x)    PRINT_CHR_TYPE(x); PRINT_CHR_MAIN(x)
#define PRINT_BIT(x)    PRINT_BIT_TYPE(x); PRINT_BIT_MAIN(x)
#define PRINT_RAW(x)    PRINT_RAW_TYPE(x); PRINT_RAW_MAIN(x)
#define PRINT_SIZ(x)    PRINT_SIZ_TYPE(x); PRINT_SIZ_MAIN(x)
#define PRINT_FLT(x)    PRINT_FLT_TYPE(x); PRINT_FLT_MAIN(x)
#define PRINT_STR(x)    PRINT_STR_TYPE(x); PRINT_STR_MAIN(x)
#define PRINT_PTR(x)    PRINT_PTR_TYPE(x); PRINT_PTR_MAIN(x)
#define PRINT_TYP(x)    PRINT_TYP_TYPE(x); PRINT_TYP_MAIN(x)
#define PRINT_TXT(x)    PRINT_TXT_TYPE(x); PRINT_TXT_MAIN(x)
#define PRINT_NLN( )    printf("\n")

#define PRINT_INF(x) \
    do{                                                                                           \
        PRINT_FNC(x);                                                                             \
        PRINT_TYP(x);                                                                             \
        PRINT_SIZ(x);                                                                             \
        PRINT_RAW(x);                                                                             \
        PRINT_BIT(x);                                                                             \
        PRINT_PTR(x);                                                                             \
        umax type = typeid(x);                                                                    \
        switch(type){                                                                             \
            case TYPE_CHR: {                                                                      \
                PRINT_CHR_TYPE(x); PRINT_CHR_MAIN((TYPE_CHR == type) ? (char)x : 0); break;       \
            }                                                                                     \
            case TYPE_INT: {                                                                      \
                PRINT_INT_TYPE(x); PRINT_INT_MAIN((TYPE_INT == type) ? (umax)x : 0); break;       \
            }                                                                                     \
            case TYPE_FLT: {                                                                      \
                PRINT_FLT_TYPE(x); PRINT_FLT_MAIN((TYPE_FLT == type) ? (double)x : 0); break;     \
            }                                                                                     \
        }                                                                                         \
    }while (0);

/*========================================================================================*/
/*ALIASES*/

/*types*/
#define imax       intmax_t
#define umax       uintmax_t

#define iptr       intptr_t
#define uptr       uintptr_t

/*strict*/
#define i08s       int8_t
#define i16s       int16_t
#define i32s       int32_t
#define i64s       int64_t

#define u08s       uint8_t
#define u16s       uint16_t
#define u32s       uint32_t
#define u64s       uint64_t

/*least*/
#define i08l       int_least8_t
#define i16l       int_least16_t
#define i32l       int_least32_t
#define i64l       int_least64_t

#define u08l       uint_least8_t
#define u16l       uint_least16_t
#define u32l       uint_least32_t
#define u64l       uint_least64_t

/*fast*/
#define i08f       int_fast8_t
#define i16f       int_fast16_t
#define i32f       int_fast32_t
#define i64f       int_fast64_t

#define u_8f       uint_fast8_t
#define u16f       uint_fast16_t
#define u32f       uint_fast32_t
#define u64f       uint_fast64_t

#define fl32       float
#define fl64       double
#define fp32       char
#define fp64       char

typedef union allt{
    void*      voidt;
    char       chart;
    imax       imaxt;
    umax       umaxt;
    iptr       iptrt;
    uptr       uptrt;
    i08s       i08st;
    i16s       i16st;
    i32s       i32st;
    i64s       i64st;
    u08s       u_8st;
    u16s       u16st;
    u32s       u32st;
    u64s       u64st;
    i08l       i08lt;
    i16l       i16lt;
    i32l       i32lt;
    i64l       i64lt;
    u08l       u08lt;
    u16l       u16lt;
    u32l       u32lt;
    u64l       u64lt;
    i08f       i08ft;
    i16f       i16ft;
    i32f       i32ft;
    i64f       i64ft;
    u_8f       u08ft;
    u16f       u16ft;
    u32f       u32ft;
    u64f       u64ft;
    fl32       fl32t;
    fl64       fl64t;
    fp32       fp32t;
    fp64       fp64t;
}allt;

/*NUMBER*/
#define i08n(x)    (i08s)(INT8_C(x))
#define i16n(x)    (i16s)(INT16_C(x))
#define i32n(x)    (i32s)(INT32_C(x))
#define i64n(x)    (i64s)(INT64_C(x))

#define u08n(x)    (u08s)(UINT8_C(x))
#define u16n(x)    (u16s)(UINT16_C(x))
#define u32n(x)    (u32s)(UINT32_C(x))
#define u64n(x)    (u64s)(UINT64_C(x))

#define fl32n(x)    ((fl32)(x))
#define fl64n(x)    ((fl64)(x))
#define flmxn(x)    ((fl64)(x))


/*========================================================================================*/
/*TIME*/
#define T_INIT() struct timespec beg, end;
#define T_BEG()  clock_gettime(CLOCK_REALTIME, &beg)
#define T_END()  clock_gettime(CLOCK_REALTIME, &end)
#define T_PRT(T) printf("%s" T ": %5ld ns\n", buff, ((end.tv_sec - end.tv_sec) + (end.tv_nsec - beg.tv_nsec)));

/*========================================================================================*/
/*FUNCTION*/

i08s yaya_bit_position(umax x);
i08s yaya_bit_onse_bit(umax x);
umax yaya_bit_revers(umax x, umax n);
void yaya_print_bit(void *p, umax size);
void yaya_print_raw(void *p, umax size);

#endif /*YAYA_DEFINES_H_*/
