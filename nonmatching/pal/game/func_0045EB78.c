/* Not matching yet: PAL WIP; main .text 0x0045EB78, 108B. Not part of the build. */
/*
 * Best104B family h04/h06/h07 has native livecount reread/indexedLH/statehighhalf reuse, but
 * keepsbase in a2/resultina3 and foldsstatebase recompute into firstcomparison delay. Native
 * initiallyloads tablebasev1, copies ittoa3 in firstcomparison delay, computesstatebase separately
 * atadvanceentry, keepsresultina2. Thus native has oneadditional realcopy/statement scheduling
 * beyond bestbody. Directfirstglobal/capturedloopb
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 8aa40b5755a9cbb59c603e41e8af9e6271e04fe023597e0242b509be04ea0b4b
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0045EB78 nonmatching/pal/game/func_0045EB78.c --diff
 */
#include "common.h"

typedef struct {
    int f0, f4, f8, fC, f10, f14, f18;
    unsigned int f1C;
    short f20, f22, f24;
    unsigned char f26, f27;
} State;
extern State D_0023F380[];
extern u8 *D_00221484;

s32 func_0045EB78(s32 id)
{
    s32 result = -1;
    s32 index = 0;
    if (D_0023F380[0].f18 > 0) {
        u8 *base = D_00221484;
        if (*(s16 *)(base + 4) == id) {
            result = 0;
        } else {
advance:
            ++index;
            if (index < D_0023F380[0].f18) {
                if (*(s16 *)(base + ((u32)index << 4) + 4) == id)
                    result = index;
                else
                    goto advance;
            }
        }
    }
    return result;
}
