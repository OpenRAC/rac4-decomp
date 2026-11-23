/* Not matching yet: PAL WIP; main core.text 0x00131A90, 1008B. Not part of the build. */
/*
 * Full64 operators and old-count pretest repaired; defined shift masks/word packing/frame/delay
 * layout remain. Existing IEEE representation and license notice retained.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 54dc822a89470774adb8739665b5e43bfd2376ce119b123ac1acaf8087dc6162
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00131A90 nonmatching/pal/core/func_00131A90.c --diff
 */
#include "common.h"

/* @(#)fdlibm.h 5.1 93/09/24 */
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

/* Exact existing public little-endian IEEE representation; __uint32_t is a word. */
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

#define INSERT_WORDS(d,ix0,ix1)					\
do {								\
  ieee_double_shape_type iw_u;					\
  iw_u.parts.msw = (ix0);					\
  iw_u.parts.lsw = (ix1);					\
  (d) = iw_u.value;						\
} while (0)


/*
 * Adapted from Sun fdlibm e_fmod.c, https://netlib.org/fdlibm/e_fmod.c.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Native supplies the zero carrier and has no final subnormal multiply.
 */
extern f64 D_00193840[];

/* Double remainder by word-aligned shift and subtract. */
f64 func_00131A90(f64 x, f64 y) {
    s32 hx, hy, hz, ix, iy, n;
    u32 lx, ly, lz, sx, scan;
    f64 product;

    EXTRACT_WORDS(hx, lx, x);
    EXTRACT_WORDS(hy, ly, y);
    sx = (u32)hx & 0x80000000u;
    hx = (s32)((u32)hx ^ sx);
    hy = (s32)((u32)hy & 0x7fffffffu);
    if (((u32)hy | ly) == 0 || hx >= 0x7ff00000 ||
        ((u32)hy | ((ly | (0u - ly)) >> 31)) > 0x7ff00000u) {
        product = x * y;
        return product / product;
    }
    if (hx <= hy) {
        if (hx < hy || lx < ly)
            return x;
        if (lx == ly)
            return D_00193840[sx >> 31];
    }

    if (hx < 0x00100000) {
        if (hx == 0) {
            ix = -1043;
            scan = lx;
        } else {
            ix = -1022;
            scan = (u32)hx << 11;
        }
        while ((s32)scan > 0) {
            ix = (s32)((u32)ix - 1u);
            scan <<= 1;
        }
    } else {
        ix = (hx >> 20) - 1023;
    }
    if (hy < 0x00100000) {
        if (hy == 0) {
            iy = -1043;
            scan = ly;
        } else {
            iy = -1022;
            scan = (u32)hy << 11;
        }
        while ((s32)scan > 0) {
            iy = (s32)((u32)iy - 1u);
            scan <<= 1;
        }
    } else {
        iy = (hy >> 20) - 1023;
    }

    if (ix >= -1022) {
        hx = (s32)(0x00100000u | ((u32)hx & 0x000fffffu));
    } else {
        n = (s32)((u32)-1022 - (u32)ix);
        if (n <= 31) {
            hx = (s32)(((u32)hx << ((u32)n & 31u)) |
                       (lx >> ((0u - (u32)n) & 31u)));
            lx <<= (u32)n & 31u;
        } else {
            hx = (s32)(lx << (((u32)n - 32u) & 31u));
            lx = 0;
        }
    }
    if (iy >= -1022) {
        hy = (s32)(0x00100000u | ((u32)hy & 0x000fffffu));
    } else {
        n = (s32)((u32)-1022 - (u32)iy);
        if (n <= 31) {
            hy = (s32)(((u32)hy << ((u32)n & 31u)) |
                       (ly >> ((0u - (u32)n) & 31u)));
            ly <<= (u32)n & 31u;
        } else {
            hy = (s32)(ly << (((u32)n - 32u) & 31u));
            ly = 0;
        }
    }

    n = (s32)((u32)ix - (u32)iy);
    while (n != 0) {
        n = (s32)((u32)n - 1u);
        hz = (s32)((u32)hx - (u32)hy - (lx < ly));
        lz = lx - ly;
        if (hz < 0) {
            hx = (s32)((u32)hx + (u32)hx + (lx >> 31));
            lx += lx;
        } else {
            if (((u32)hz | lz) == 0)
                return D_00193840[sx >> 31];
            hx = (s32)((u32)hz + (u32)hz + (lz >> 31));
            lx = lz + lz;
        }
    }
    hz = (s32)((u32)hx - (u32)hy - (lx < ly));
    lz = lx - ly;
    if (hz >= 0) {
        hx = hz;
        lx = lz;
    }
    if (((u32)hx | lx) == 0)
        return D_00193840[sx >> 31];
    while (hx < 0x00100000) {
        hx = (s32)((u32)hx + (u32)hx + (lx >> 31));
        lx += lx;
        iy = (s32)((u32)iy - 1u);
    }
    if (iy >= -1022) {
        hx = (s32)(((u32)hx - 0x00100000u) |
                   (((u32)iy + 1023u) << 20));
    } else {
        n = (s32)((u32)-1022 - (u32)iy);
        if (n <= 20) {
            lx = (lx >> ((u32)n & 31u)) |
                 ((u32)hx << ((0u - (u32)n) & 31u));
            hx >>= (u32)n & 31u;
        } else {
            if (n <= 31)
                lx = ((u32)hx << ((0u - (u32)n) & 31u)) |
                     (lx >> ((u32)n & 31u));
            else
                lx = (u32)(hx >> (((u32)n - 32u) & 31u));
            hx = (s32)sx;
        }
    }
    INSERT_WORDS(x, (u32)hx | sx, lx);
    return x;
}
