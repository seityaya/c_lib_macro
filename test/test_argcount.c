// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "stdarg.h"
#include "stdio.h"

#include "yaya_argcount.h"

enum {
    BUF_SIZE = 128
};

static int argcount_func(char *buf, int count, ...) {
    int offset = 0;
    va_list argptr;
    va_start(argptr, count);
    for (int i = 0; i < count; i++) {
        int x = va_arg(argptr, int);
        offset += snprintf(&buf[offset], BUF_SIZE, "%d ", x);
    }
    va_end(argptr);
    return count;
}

#define EATER0(...)
#define EATER1(...) ,
#define EATER2(...) (/*empty*/)
#define EATER3(...) (/*empty*/),
#define EATER4(...) EATER1
#define EATER5(...) EATER2
#define MAC0() ()
#define MAC1(x) ()
#define MACV(...) ()
#define MAC2(x, y) (z)

UT_FUNC_GEN(test_argcount) {
    UT_GROUP_BEG(macro_for_macro) {
        UT_ASSERT_NUM_EQ(0, ARGCOUNT());
        UT_ASSERT_NUM_EQ(0, ARGCOUNT(/*comment*/));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(a));
        UT_ASSERT_NUM_EQ(2, ARGCOUNT(a, b));
        UT_ASSERT_NUM_EQ(3, ARGCOUNT(a, b, c));
        UT_ASSERT_NUM_EQ(4, ARGCOUNT(a, b, c, d));
        UT_ASSERT_NUM_EQ(5, ARGCOUNT(a, b, c, d, e));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT((a, b, c, d, e)));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT((void)));
        UT_ASSERT_NUM_EQ(3, ARGCOUNT((void), c, d));
        UT_ASSERT_NUM_EQ(3, ARGCOUNT((a, b), c, d));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(_TRIGGER_PARENTHESIS_));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(EATER0));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(EATER1));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(EATER2));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(EATER3));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(EATER4));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(MAC0));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(MAC1));
        UT_ASSERT_NUM_EQ(1, ARGCOUNT(MACV));
    }
    UT_GROUP_END;

    UT_GROUP_BEG(macro_for_func) {
        char buf[BUF_SIZE] = {0};
        char *buf_p = buf;

        int a = 1;
        int b = 2;
        int c = 3;
        int d = 4;
        int e = 5;

        buf[0] = '\0';
        UT_ASSERT_NUM_EQ(5, argcount_func(buf, 5, a, b, c, d, e));
        UT_ASSERT_STR_EQ("1 2 3 4 5 ", buf_p);

        buf[0] = '\0';
        UT_ASSERT_NUM_EQ(0, argcount_func(buf, ARGCOUNT_AND_ARGS()));
        UT_ASSERT_STR_EQ("", buf_p);

        buf[0] = '\0';
        UT_ASSERT_NUM_EQ(0, argcount_func(buf, ARGCOUNT_AND_ARGS(/*comment*/)));
        UT_ASSERT_STR_EQ("", buf_p);

        buf[0] = '\0';
        UT_ASSERT_NUM_EQ(1, argcount_func(buf, ARGCOUNT_AND_ARGS('a')));
        UT_ASSERT_STR_EQ("97 ", buf_p);

        buf[0] = '\0';
        UT_ASSERT_NUM_EQ(2, argcount_func(buf, ARGCOUNT_AND_ARGS('a', 'b')));
        UT_ASSERT_STR_EQ("97 98 ", buf_p);

        buf[0] = '\0';
        UT_ASSERT_NUM_EQ(5, argcount_func(buf, ARGCOUNT_AND_ARGS(a, b, c, d, e)));
        UT_ASSERT_STR_EQ("1 2 3 4 5 ", buf_p);

        /* TODO
         * Warning: Left operand of comma operator has no effect
         * Warning: Expression result unused
         * Warning: Statement no effect
         * It's OK
         */

//        buf[0] = '\0';
//        UT_ASSERT_NUM_EQ(4, argcount_func(buf, ARGCOUNT_AND_ARGS((a, b), c, d, e)));
//        UT_ASSERT_STR_EQ("2 3 4 5 ", buf_p);

//        buf[0] = '\0';
//        UT_ASSERT_NUM_EQ(4, argcount_func(buf, ARGCOUNT_AND_ARGS( ({a; b;}), c, d, e)));
//        UT_ASSERT_STR_EQ("2 3 4 5 ", buf_p);
    }
    UT_GROUP_END;
}
