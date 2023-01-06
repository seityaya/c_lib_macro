#include "stdio.h"

bool f(i08s x){
    if(x > 5){
        return x;
    }else{
        return -1;
    }
}

struct A{
    int a;
    int b;
} A_std = { .a = 1, .b = 1 },
          A_null = { .a = 0, .b = 0};

typedef struct A A_t;

UNIT_TEST_GENERATE_FUNC(MATH){
    {
        A_t aa;

        aa = A_std;
        PRINT_INT(aa.a);

        aa = A_null;
        PRINT_INT(aa.a);
    }

    PRINT_LOC();

    u16s R = u16n(-158);

    PRINT_INT(R);
    PRINT_TYP(R);

    PRINT_TXT( zxdhnb );

    char *text = "This is a text";

    PRINT_STR(text);

    PRINT_NLN();

    PRINT_TXT("BIT SET");

    uint32_t k = 0;
    //    uint64_t t = 0;

    k = BIT_SET(k, 1);
    k = BIT_REV(k);

    k = BIT_SET(k, 10);

    k = BIT_SET(k, 17);
    k = BIT_SET(k, 18);

    k = BIT_SET(k, 27);

    k = BIT_SET(k, 33);
    k = BIT_SET(k, 35);

    k = BIT_SET(k, 42);
    k = BIT_SET(k, 43);

    k = BIT_SET(k, 49);
    k = BIT_SET(k, 50);
    k = BIT_SET(k, 51);

    k = BIT_SET(k, 60);

    PRINT_INT(k);
    PRINT_BIT(k);
    PRINT_RAW(k);
    PRINT_TYP(k);
    PRINT_NLN();

    PRINT_TXT("BIT REV");
    k = BIT_REV(k);
    PRINT_INT(k);
    PRINT_BIT(k);
    PRINT_RAW(k);
    PRINT_TYP(k);
    PRINT_NLN();

u16s x = 54321, t = k;

        PRINT_TXT("8 -> 1");

        (((uint8_t*)(&t)) [0]) = 8;
        (((uint8_t*)(&t)) [1]) = 7;
        (((uint8_t*)(&t)) [2]) = 6;
        (((uint8_t*)(&t)) [3]) = 5;
        (((uint8_t*)(&t)) [4]) = 4;
        (((uint8_t*)(&t)) [5]) = 3;
        (((uint8_t*)(&t)) [6]) = 2;
        (((uint8_t*)(&t)) [7]) = 1;



        PRINT_INT(t);
        PRINT_BIT(t);
        PRINT_RAW(t);
        PRINT_TYP(t);;
        PRINT_NLN();

        PRINT_TXT("1 -> 8");

        (((uint8_t*)(&t)) [0]) = 1;
        (((uint8_t*)(&t)) [1]) = 2;
        (((uint8_t*)(&t)) [2]) = 3;
        (((uint8_t*)(&t)) [3]) = 4;
        (((uint8_t*)(&t)) [4]) = 5;
        (((uint8_t*)(&t)) [5]) = 6;
        (((uint8_t*)(&t)) [6]) = 7;
        (((uint8_t*)(&t)) [7]) = 8;



        PRINT_INT(t);
        PRINT_BIT(t);
        PRINT_RAW(t);
        PRINT_TYP(t);
        PRINT_NLN();

        PRINT_TXT("FLAG_SET(1) - 1  ->  FLAG_SET(8) - 1");

        (((uint8_t*)(&t)) [0]) = FLAG_SET(1) - 1;
        (((uint8_t*)(&t)) [1]) = FLAG_SET(2) - 1;
        (((uint8_t*)(&t)) [2]) = FLAG_SET(3) - 1;
        (((uint8_t*)(&t)) [3]) = FLAG_SET(4) - 1;
        (((uint8_t*)(&t)) [4]) = FLAG_SET(5) - 1;
        (((uint8_t*)(&t)) [5]) = FLAG_SET(6) - 1;
        (((uint8_t*)(&t)) [6]) = FLAG_SET(7) - 1;
        (((uint8_t*)(&t)) [7]) = FLAG_SET(8) - 1;

        PRINT_INT(t);
        PRINT_BIT(t);
        PRINT_RAW(t);
        PRINT_TYP(t);
        PRINT_NLN();


        PRINT_TXT("FLAG_SET(1) + 1  ->  FLAG_SET(8) + 1");
        (((int8_t*)(&t)) [0]) = FLAG_SET(1) + 1;
        (((int8_t*)(&t)) [1]) = FLAG_SET(2) + 1;
        (((int8_t*)(&t)) [2]) = FLAG_SET(3) + 1;
        (((int8_t*)(&t)) [3]) = FLAG_SET(4) + 1;
        (((int8_t*)(&t)) [4]) = FLAG_SET(5) + 1;
        (((int8_t*)(&t)) [5]) = FLAG_SET(6) + 1;
        (((int8_t*)(&t)) [6]) = FLAG_SET(7) + 1;
        (((int8_t*)(&t)) [7]) = FLAG_SET(8) + 1;

        PRINT_INT(t);
        PRINT_BIT(t);
        PRINT_RAW(t);
        PRINT_TYP(t);
        PRINT_NLN();


        PRINT_TXT("FLAG_SET(1) + 1  ->  FLAG_SET(8) + 1");
        (((int8_t*)(&t)) [0]) = FLAG_SET(1) + 1;
        (((int8_t*)(&t)) [1]) = FLAG_SET(2) + 1;
        (((int8_t*)(&t)) [2]) = FLAG_SET(3) + 1;
        (((int8_t*)(&t)) [3]) = FLAG_SET(4) + 1;
        (((int8_t*)(&t)) [4]) = FLAG_SET(5) + 1;
        (((int8_t*)(&t)) [5]) = FLAG_SET(6) + 1;
        (((int8_t*)(&t)) [6]) = FLAG_SET(7) + 1;
        (((int8_t*)(&t)) [7]) = FLAG_SET(8) + 1;

        PRINT_INT(t);
        PRINT_BIT(t);
        PRINT_RAW(t);
        PRINT_TYP(t);
        PRINT_NLN();



    PRINT_LOC(x);
    PRINT_FNC(x);
    PRINT_INT(x);
    PRINT_BIT(x);
    PRINT_RAW(x);
    PRINT_PTR(x);
    PRINT_CHR(x);
    PRINT_SIZ(x);
    PRINT_FLT(x);
    PRINT_STR(x);
    PRINT_TYP(x);
    PRINT_TXT(x);
















#define VAR 4
#if VAR == 0
    int orZ = 1;
    int z = orZ;
#elif VAR == 1
     int orZ = 1;
     int *z = &orZ;
#elif VAR == 2
    double orZ = 1;
    double Z = orZ;
#elif VAR == 3
    double orZ = 1;
    double* z = &orZ;
#elif VAR == 4
    char orZ = 1;
    char* z = &orZ;
#endif

PRINT_INF(orZ);

//    do{
//        PRINT_LOC(x);
//        PRINT_FNC(x);
//        PRINT_TYP(x);
//        PRINT_SIZ(x);
//        PRINT_RAW(x);
//        PRINT_BIT(x);
//        PRINT_PTR(x);
//        umax type = typeid(x);
//        allt X;
//        X.umaxt = (umax)x;
//        switch(type){
//            case TYPE_CHR: {
//                PRINT_CHR_TYPE(x); PRINT_CHR_MAIN(X.chart); break;
//            }
//            case TYPE_INT: {
//                PRINT_INT_TYPE(x); PRINT_INT_MAIN(X.umaxt); break;
//            }
//            case TYPE_FLT: {
//                PRINT_FLT_TYPE(x); PRINT_FLT_MAIN(X.fl64t); break;
//            }
//            case TYPE_CHR_P: {
//                X.chart = (char)(*x);
//                PRINT_CHR_TYPE(x); PRINT_CHR_MAIN((TYPE_CHR == type) ? (char)(*x) : (char)(x)); break;
//            }
//            case TYPE_INT_P: {
//                PRINT_INT_TYPE(x); PRINT_INT_MAIN((TYPE_INT == type) ? (umax)(*x) : (umax)(*x)); break;
//            }
//            case TYPE_FLT_P: {
//                PRINT_FLT_TYPE(x); PRINT_FLT_MAIN((TYPE_FLT == type) ? (double)(*x) : (double)(x)); break;
//            }
//        }
//    }while (0);
}