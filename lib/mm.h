#ifndef MM_H
#define MM_H

#define CMP(x, y, op) ((x) op (y) ? (x) : (y))

#define CMP_ONSE_2(x, y, unique_x, unique_y, op) ({	\
        typeof(x) unique_x = (x);		\
        typeof(y) unique_y = (y);		\
        CMP(unique_x, unique_y, op); })

#define CMP_ONSE(x, y, op) CMP_ONSE_2(x, y, __UNIQUE_ID(__x), __UNIQUE_ID(__y), <)

#define MIN(x,y)  CMP_ONSE(x, y, <)
#define MAX(a,b)  CMP_ONSE(x, y, >)
#define SWAP(a,b) { typeof(a) tmp = a; a = b; b = tmp; }










#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

/*
 * min()/max()/clamp() macros must accomplish three things:
 *
 * - avoid multiple evaluations of the arguments (so side-effects like
 *   "x++" happen only once) when non-constant.
 * - perform strict type-checking (to generate warnings instead of
 *   nasty runtime surprises). See the "unnecessary" pointer comparison
 *   in __typecheck().
 * - retain result as a constant expressions when called with only
 *   constant expressions (to avoid tripping VLA warnings in stack
 *   allocation usage).
 */
#define __typecheck(x, y) \
    (!!(sizeof((typeof(x) *)1 == (typeof(y) *)1)))

/*
 * This returns a constant expression while determining if an argument is
 * a constant expression, most importantly without evaluating the argument.
 * Glory to Martin Uecker <Martin.Uecker@med.uni-goettingen.de>
 */
#define __is_constexpr(x) \
    (sizeof(int) == sizeof(*(8 ? ((void *)((long)(x) * 0l)) : (int *)8)))

#define __no_side_effects(x, y) \
        (__is_constexpr(x) && __is_constexpr(y))

#define __safe_cmp(x, y) \
        (__typecheck(x, y) && __no_side_effects(x, y))

#define __cmp(x, y, op)	((x) op (y) ? (x) : (y))

#define __cmp_once(x, y, unique_x, unique_y, op) ({	\
        typeof(x) unique_x = (x);		\
        typeof(y) unique_y = (y);		\
        __cmp(unique_x, unique_y, op); })

#define __careful_cmp(x, y, op) \
    __builtin_choose_expr(__safe_cmp(x, y), \
        __cmp(x, y, op), \
        __cmp_once(x, y, __UNIQUE_ID(__x), __UNIQUE_ID(__y), op))

/**
 * min - return minimum of two values of the same or compatible types
 * @x: first value
 * @y: second value
 */
#define min(x, y)	__careful_cmp(x, y, <)

/**
 * max - return maximum of two values of the same or compatible types
 * @x: first value
 * @y: second value
 */
#define max(x, y)	__careful_cmp(x, y, >)

#endif // MM_H
