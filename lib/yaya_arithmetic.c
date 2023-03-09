//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "stdlib.h"
#include "string.h"
#include "malloc.h"

#include "yaya_arithmetic.h"
#include "yaya_number.h"
#include "yaya_rand.h"

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

umax_t ___gcd(umax_t u, umax_t v) {
    if (v < u) {
        swap(v, u);
    }
    while((u %= v) && (v %= u)) {
        ;
    }
    return (u+v);
}

umax_t ___lcm(umax_t u, umax_t v) {
    return __mul(__div(u, ___gcd(u, v)), v);
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
    for(umax_t i = 3; (i * i) <= p; i += 2) {
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
        if (r >= typemax(n)/n) {  /* Possible overflow */
            umax_t nr = 0; /* reduced numerator */
            umax_t dr = 0; /* reduced denominator */
            g = ___gcd(n, d);
            nr = n/g;
            dr = d/g;
            g = ___gcd(r, dr);
            r = r/g;
            dr = dr/g;
            if (r >= typemax(nr) / nr) {
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

umax_t ___divisors(umax_t n, umax_t* m[]) {
    if(n == 0) {
        return 0;
    }

    umax_t msize = 0;
    if(m != NULL) {
        (*m) = (umax_t*)(calloc(1, sizeof(umax_t)));
        msize = malloc_usable_size(*m);
    }

    umax_t count = 0;
    for(umax_t i = 1; i < ((n / 2) + 1); i++) {
        if(n % i == 0) {
            if(m != NULL) {
                if((count + 1) == msize / sizeof(umax_t)) {
                    (*m) = (umax_t*)(realloc(*m, (msize + 1) * sizeof(umax_t)));
                    msize =  malloc_usable_size(*m);
                }
                (*m)[count] = i;
                (*m)[count + 1] = n;
            }
            count++;
        }
    }
    return count + 1;
}

umax_t ___primes(umax_t n, umax_t* m[]) {
    if (n <= 1) {
        return 0;
    }

    umax_t msize = 0;
    if(m != NULL) {
        (*m) = (umax_t*)(calloc(1, sizeof(umax_t)));
        msize = malloc_usable_size(*m);
    }

    umax_t count = 0;
    for (umax_t i = 1; i <= n; i += 2) {
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

END_C_DECLARATION
