// Author                 : Seityagiya Terlekchi
// Contacts               : terlekchiseityaya@gmail.com
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2025 Seityagiya Terlekchi. All rights reserved.

#include "stdarg.h"
#include "stdio.h"
#include "test.h"
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

int test_argcount(void) {
    {
        ASSERT_NUM_EQ(0, ARGCOUNT());
        ASSERT_NUM_EQ(0, ARGCOUNT(/*comment*/));
        ASSERT_NUM_EQ(1, ARGCOUNT(a));
        ASSERT_NUM_EQ(2, ARGCOUNT(a, b));
        ASSERT_NUM_EQ(3, ARGCOUNT(a, b, c));
        ASSERT_NUM_EQ(4, ARGCOUNT(a, b, c, d));
        ASSERT_NUM_EQ(5, ARGCOUNT(a, b, c, d, e));
        ASSERT_NUM_EQ(1, ARGCOUNT((a, b, c, d, e)));
        ASSERT_NUM_EQ(1, ARGCOUNT((void)));
        ASSERT_NUM_EQ(3, ARGCOUNT((void), c, d));
        ASSERT_NUM_EQ(3, ARGCOUNT((a, b), c, d));
        ASSERT_NUM_EQ(1, ARGCOUNT(_TRIGGER_PARENTHESIS_));
        ASSERT_NUM_EQ(1, ARGCOUNT(EATER0));
        ASSERT_NUM_EQ(1, ARGCOUNT(EATER1));
        ASSERT_NUM_EQ(1, ARGCOUNT(EATER2));
        ASSERT_NUM_EQ(1, ARGCOUNT(EATER3));
        ASSERT_NUM_EQ(1, ARGCOUNT(EATER4));
        ASSERT_NUM_EQ(1, ARGCOUNT(MAC0));
        ASSERT_NUM_EQ(1, ARGCOUNT(MAC1));
        ASSERT_NUM_EQ(1, ARGCOUNT(MACV));
    }

    {
        char buf[BUF_SIZE] = {0};

        int a = 1;
        int b = 2;
        int c = 3;
        int d = 4;
        int e = 5;

        buf[0] = '\0';
        ASSERT_NUM_EQ(5, argcount_func(buf, 5, a, b, c, d, e));
        ASSERT_STR_EQ("1 2 3 4 5 ", buf);

        buf[0] = '\0';
        ASSERT_NUM_EQ(0, argcount_func(buf, ARGCOUNT_AND_ARGS()));
        ASSERT_STR_EQ("", buf);

        buf[0] = '\0';
        ASSERT_NUM_EQ(0, argcount_func(buf, ARGCOUNT_AND_ARGS(/*comment*/)));
        ASSERT_STR_EQ("", buf);

        buf[0] = '\0';
        ASSERT_NUM_EQ(1, argcount_func(buf, ARGCOUNT_AND_ARGS('a')));
        ASSERT_STR_EQ("97 ", buf);

        buf[0] = '\0';
        ASSERT_NUM_EQ(2, argcount_func(buf, ARGCOUNT_AND_ARGS('a', 'b')));
        ASSERT_STR_EQ("97 98 ", buf);

        buf[0] = '\0';
        ASSERT_NUM_EQ(5, argcount_func(buf, ARGCOUNT_AND_ARGS(a, b, c, d, e)));
        ASSERT_STR_EQ("1 2 3 4 5 ", buf);

        /* NOTE
         * Warning: Left operand of comma operator has no effect
         * Warning: Expression result unused
         * Warning: Statement no effect
         * It's OK
         */

        // buf[0] = '\0';
        // ASSERT_NUM_EQ(4, argcount_func(buf, ARGCOUNT_AND_ARGS((a, b), c, d, e))); ASSERT_STR_EQ("2 3 4 5 ", buf);

        // buf[0] = '\0';
        // ASSERT_NUM_EQ(4, argcount_func(buf, ARGCOUNT_AND_ARGS( ({a; b;}), c, d, e))); ASSERT_STR_EQ("2 3 4 5 ", buf);
    }

    return 0;
}
