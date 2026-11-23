/* Not matching yet: PAL WIP; level_02 .text 0x004DE168, 208B. Not part of the build. */
/*
 * Native initial stride a1 / highpart v0 copied t0; h01 initial realarray LUI+ADDIU consumes v0
 * directly, stride a0, capturedentry a0 versusnativea1. Native later reuses highpart t0-3100 and
 * store displacements2D8/2C8. h01 rematerializes array+2D8 via LUI+ADDIU and stores0/-10.
 * One-prefix-word shift until common store arm, revised branch displacements, differing MULT/SH
 * scheduling. All39 actual unmatched words listed i
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 8f8a87734bb91cbf0817f6cbc2f87f6d22b68427051ca06572568bb9eea9cff6
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L02_004DE168 nonmatching/pal/shared/func_L02_004DE168.c --diff
 */
#include "common.h"

extern u8 D_00230380[];
extern s32 D_0021DE3C;
extern s32 D_0021E764;

void func_L02_004DE168(void *object)
{
    u8 *obj = object;
    u8 *entry = D_00230380 + (*(u32 *)(obj + 0x94) * 0x470U);
    u8 *part = entry + 0x150;
    s16 current = *(s16 *)(obj + 0x86);
    s32 mode;

    if (*(s32 *)(part + 0xFC) != current || D_0021DE3C != 0 ||
        ((mode = D_0021E764) != 0 && mode != -2)) {
        s32 code = *(s32 *)(part + 0xFC);
        if (code != 4 && code != 0x51) {
            u32 index;
            *(u8 *)(entry + 0x2B3) = 0;
            index = *(u32 *)(obj + 0x94);
            *(s16 *)(obj + 0x7E) = 2;
            *(f32 *)(D_00230380 + index * 0x470U + 0x2D8) = 0.045f;
            *(f32 *)(D_00230380 + (*(u32 *)(obj + 0x94) * 0x470U) + 0x2C8) = 0.045f;
        } else {
            *(s32 *)(entry + 0x468) = 2;
            *(s16 *)(obj + 0x7E) = 1;
        }
    }
}
