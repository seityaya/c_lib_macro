// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_cdecl.h"
BEG_C_DECLARATION

#include "stdlib.h"
#include "string.h"
#include "malloc.h"

#include "yaya_arithmetic.h"
#include "yaya_rand.h"

umax_t ___gcd(umax_t u, umax_t v) {
    if (u == 0 && v == 0) {
        return 0;
    }
    if (v == 0) {
        return u;
    }
    if (u == 0) {
        return v;
    }

    while (true) {
        v %= u;
        if (v == 0) {
            break;
        }

        u %= v;
        if (u == 0) {
            break;
        }
    }
    return (u + v);
}

umax_t ___lcm(umax_t u, umax_t v) {
    if (u == 0 || v == 0) {
        return 0;
    }

    umax_t M = max(v, u);
    umax_t m = min(v, u);
    umax_t r = M;

    while (true) {
        if (r % m == 0) {
            break;
        }
        r += M;
    }
    return r;
}

umax_t ___isqrt(umax_t x) {
    umax_t q = 1;
    while (q <= x) {
        q <<= 2;
    }

    umax_t r = 0;
    while (q > 1) {
        umax_t t = 0;
        q >>= 2;
        t = x - r - q;
        r >>= 1;
        if (t >= 0) {
            x = t;
            r += q;
        }
    }
    return r;
}

bool_t ___is_prime(umax_t p) {
    if (p <= 1) {
        return false;
    }
    if (p == 2) {
        return true;
    }
    if (!(p % 2)) {
        return false;
    }

    umax_t r = ___isqrt(p);
    for(umax_t i = 3; i <= r; i += 2) {
        if(!(p % i)) {
            return false;
        }
    }
    return true;
}


umax_t ___primenum(umax_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 2;
    }

    umax_t pn = 1;
    umax_t p = 0;
    for(p = 3; pn < n; p += 2) {
        if(___is_prime(p)) {
            pn++;
        }
    }
    return p - 2;
}

umax_t ___fibonacci(umax_t n){
    if (n == 0) {
        return 0;
    }

    umax_t ftnow = 0;
    umax_t fnext = 1;
    umax_t tempf = 0;
    while (--n > 0) {
        tempf = ftnow + fnext;
        ftnow = fnext;
        fnext = tempf;
    }
    return fnext;
}

umax_t ___factorial(umax_t n){
    umax_t fact = 1;
    for (umax_t i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

umax_t ___binomial(umax_t n, umax_t k) {
    if (k > n) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    if (k == n) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    if (k > n/2) {
        k = n-k;
    }

    umax_t g = 0;
    umax_t r = 1;
    for (umax_t d = 1; d <= k; d++) {
        if (r >= base_type_max(n)/n) {  /* Possible overflow */
            umax_t nr = 0; /* reduced numerator */
            umax_t dr = 0; /* reduced denominator */
            g = ___gcd(n, d);
            nr = n/g;
            dr = d/g;
            g = ___gcd(r, dr);
            r = r/g;
            dr = dr/g;
            if (r >= base_type_max(nr) / nr) {
                return 0;  /* Unavoidable overflow */
            }
            r *= nr;
            r /= dr;
            n--;
        } else {
            r *= n--;
            r /= d;
        }
    }
    return r;
}

umax_t ___divisors(umax_t k, umax_t* m[]) {
    if(k == 0) {
        return 0;
    }

    umax_t msize = 0;
    if(m != NULL) {
        (*m) = (umax_t*)(calloc(1, sizeof(umax_t)));
        msize = malloc_usable_size(*m);
    }

    umax_t count = 0;
    for(umax_t i = 1; i < ((k / 2) + 1); i++) {
        if(k % i == 0) {
            if(m != NULL) {
                if((count + 1) == msize / sizeof(umax_t)) {
                    (*m) = (umax_t*)(realloc(*m, (msize + 1) * sizeof(umax_t)));
                    msize =  malloc_usable_size(*m);
                }
                (*m)[count] = i;
                (*m)[count + 1] = k;
            }
            count++;
        }
    }
    return count + 1;
}

umax_t ___primes(umax_t k, umax_t* m[]) {
    if (k <= 1) {
        return 0;
    }

    umax_t msize = 0;
    if(m != NULL) {
        (*m) = (umax_t*)(calloc(1, sizeof(umax_t)));
        msize = malloc_usable_size(*m);
    }

    umax_t count = 0;
    for (umax_t i = 1; i <= k; i += 2) {
        bool_t flag = true;
        for(umax_t j = 2; j < i; j++) {
            if (!(i % j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(m != NULL) {
                if((count + 1) == msize / sizeof(umax_t)) {
                    (*m) = (umax_t*)(realloc(*m, (msize + 1) * sizeof(umax_t)));
                    msize =  malloc_usable_size(*m);
                }
                (*m)[count] = i;
                (*m)[0] = 2;
            }
            count++;
        }
    }
    return count;
}


umax_t ___permutation(umax_t n, const umax_t* m){
    if(m == NULL) {
        return ___factorial(n);
    }

    umax_t k = 1;
    umax_t l = 0;
    for (umax_t i = 0; i < n; i++) {
        k *= ___factorial(m[i]);
        l += m[i];
    }
    return __div(___factorial(l), k);
}

umax_t ___accommodation(umax_t n, umax_t k, bool_t f){
    if(k > n) {
        return 0;
    }
    if(f) {
        return __powm(n, k);
    }
    else {
        return __div(___factorial(n), ___factorial(n - k));
    }
}

umax_t ___combination(umax_t n, umax_t k, bool_t f){
    if(k > n) {
        return 0;
    }
    if(f) {
        if(n == 0) {
            return 0;
        }
        return __div(___factorial(n + k - 1), __mul(___factorial(k), ___factorial(n - 1)));
    }
    else {
        return __div(___factorial(n), __mul(___factorial(k), ___factorial(n - k)));
    }
}

inline char   ___abs_char(char   x){ return __to_pos(x); }
inline is8_t  ___abs_is8 (is8_t  x){ return __to_pos(x); }
inline is16_t ___abs_is16(is16_t x){ return __to_pos(x); }
inline is32_t ___abs_is32(is32_t x){ return __to_pos(x); }
inline is64_t ___abs_is64(is64_t x){ return __to_pos(x); }
inline us8_t  ___abs_us8 (us8_t  x){ return __to_pos(x); }
inline us16_t ___abs_us16(us16_t x){ return __to_pos(x); }
inline us32_t ___abs_us32(us32_t x){ return __to_pos(x); }
inline us64_t ___abs_us64(us64_t x){ return __to_pos(x); }

inline char   ___pow_char(char   x, char   p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline is8_t  ___pow_is8 (is8_t  x, is8_t  p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline is16_t ___pow_is16(is16_t x, is16_t p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline is32_t ___pow_is32(is32_t x, is32_t p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline is64_t ___pow_is64(is64_t x, is64_t p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline us8_t  ___pow_us8 (us8_t  x, us8_t  p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline us16_t ___pow_us16(us16_t x, us16_t p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline us32_t ___pow_us32(us32_t x, us32_t p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }
inline us64_t ___pow_us64(us64_t x, us64_t p){ typeof(x) __x = 1; typeof(p) __p = p; while(__p--){ __as(__x, __x * x); } return __x; }

inline char   ___copysign_char(char   r, char   s){ (void)(r); return ((s) > 0) ? __to_pos(one(s)) : (((s) < 0) ? __to_neg(one(s)) : zero(s)); }
inline is8_t  ___copysign_is8 (is8_t  r, is8_t  s){ (void)(r); return ((s) > 0) ? __to_pos(one(s)) : (((s) < 0) ? __to_neg(one(s)) : zero(s)); }
inline is16_t ___copysign_is16(is16_t r, is16_t s){ (void)(r); return ((s) > 0) ? __to_pos(one(s)) : (((s) < 0) ? __to_neg(one(s)) : zero(s)); }
inline is32_t ___copysign_is32(is32_t r, is32_t s){ (void)(r); return ((s) > 0) ? __to_pos(one(s)) : (((s) < 0) ? __to_neg(one(s)) : zero(s)); }
inline is64_t ___copysign_is64(is64_t r, is64_t s){ (void)(r); return ((s) > 0) ? __to_pos(one(s)) : (((s) < 0) ? __to_neg(one(s)) : zero(s)); }
inline us8_t  ___copysign_us8 (us8_t  r, us8_t  s){ (void)(r); return one(s); }
inline us16_t ___copysign_us16(us16_t r, us16_t s){ (void)(r); return one(s); }
inline us32_t ___copysign_us32(us32_t r, us32_t s){ (void)(r); return one(s); }
inline us64_t ___copysign_us64(us64_t r, us64_t s){ (void)(r); return one(s); }

END_C_DECLARATION
