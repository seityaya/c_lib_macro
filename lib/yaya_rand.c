//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_cdeclaration.h"
BEG_C_DECLARATION

#include "yaya_number.h"
#include "yaya_unused.h"

umax_t __rand_seed = 0;

fmax_t __get_rand_normal(fmax_t mu, fmax_t sigma){ /* FIXME IMPLEMENT */
    UNUSED_VAR(mu);
    UNUSED_VAR(sigma);
    return 0.0;
}

fmax_t __get_rand_beta(fmax_t a, fmax_t b){        /* FIXME IMPLEMENT */
    UNUSED_VAR(a);
    UNUSED_VAR(b);
    return 0.0;
}

END_C_DECLARATION
