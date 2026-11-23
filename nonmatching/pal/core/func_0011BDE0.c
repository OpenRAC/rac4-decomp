/* Not matching yet: PAL WIP; main core.text 0x0011BDE0, 424B. Not part of the build. */
/*
 * Log callee0x0011B7C8 is native-only, not MATCH. Full64 operands repaired, but generated24B
 * constant pool, real relocations, frame/packing/scheduling remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 79b8ca6a34f1bee4b704c3590760459eb34adf4d1ca156123292ecb49c89bc1e
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0011BDE0 nonmatching/pal/core/func_0011BDE0.c --diff
 */
#include "common.h"

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/* Exact existing fdlibm.h IEEE representation fragments, recovered without
 * its unavailable transitive math.h/machine includes. */
typedef u32 __uint32_t;

typedef union 
{
  double value;
  struct 
  {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

#define EXTRACT_WORDS(ix0,ix1,d)				\
do {								\
  ieee_double_shape_type ew_u;					\
  ew_u.value = (d);						\
  (ix0) = ew_u.parts.msw;					\
  (ix1) = ew_u.parts.lsw;					\
} while (0)

#define GET_HIGH_WORD(i,d)					\
do {								\
  ieee_double_shape_type gh_u;					\
  gh_u.value = (d);						\
  (i) = gh_u.parts.msw;						\
} while (0)

#define SET_HIGH_WORD(d,v)					\
do {								\
  ieee_double_shape_type sh_u;					\
  sh_u.value = (d);						\
  sh_u.parts.msw = (v);						\
  (d) = sh_u.value;						\
} while (0)

/* Actual native-only full-double log ABI; no helper implementation here. */
f64 func_0011B7C8(f64 value);
extern f64 D_00192188[];

f64 func_0011BDE0(f64 x)
{
    s32 high;
    u32 low;
    s32 exponent;
    u32 sign;
    f64 y;
    f64 logarithm;
    f64 lowPart;
    f64 combined;
    f64 left;
    f64 right;

    EXTRACT_WORDS(high, low, x);
    exponent = 0;
    if (high <= 0x000FFFFF) {
        if ((((u32)high & 0x7FFFFFFFU) | low) == 0) {
            return D_00192188[0];
        }
        if (high < 0) {
            return 0.0;
        }
        exponent = -54;
        x = x * 18014398509481984.0;
        GET_HIGH_WORD(high, x);
    }
    if (high > 0x7FEFFFFF) {
        left = x;
        right = x;
    } else {
        exponent = (s32)((u32)exponent - 1023U + (u32)(high >> 20));
        sign = (u32)exponent >> 31;
        high = (s32)(((u32)high & 0x000FFFFFU) | ((1023U - sign) << 20));
        y = (f64)(s32)((u32)exponent + sign);
        SET_HIGH_WORD(x, high);
        logarithm = func_0011B7C8(x);
        lowPart = y * 3.694239077158931e-13;
        combined = lowPart + logarithm * 0.4342944819032518;
        left = combined;
        right = y * 0.30102999566361177;
    }
    return left + right;
}
