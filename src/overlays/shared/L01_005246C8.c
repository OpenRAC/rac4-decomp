#include "common.h"

extern s32 D_222990;
extern u8 *D_3660F8[];
extern s32 func_L00_006F3958(void *);
extern s32 func_L01_00524598(u8 *actor);

// Decides whether the actor may act: counts the entries of its list that pass a test, then checks its flags.
s32 func_L01_005246C8(u8 *arg0, u8 *arg1)
{
    u8 *s6;
    u8 *p;
    s32 total;
    s32 ok;
    s32 i;
    s32 t;
    s32 r;

    s6 = *(u8 **)((*(s16 *)(arg0 + 0x84) << 5) + D_222990 + 0x1C);
    if (*(s32 *)(arg0 + 0x94) != 0) {
        return 0;
    }
    if (s6[0x106] == 0) {
        p = D_3660F8[0];
        total = 0;
        ok = 0;
        i = 0;
        do {
            if (p != NULL) {
                if (*(s16 *)(p + 0x420) == 0) {
                    if (*(f32 *)(p + 0x2E20) <= 0.0f || (t = *(s32 *)(p + 0x25CC)) == 0x39 || t == 0x68 || t == 0x6A || t == 0x76 || t == 0x7A || t == 0x7B || t == 0x7E || t == 0x7F || t == 0x94 || t == 0x99 || func_L00_006F3958(p) != 0) {
                        ok++;
                    }
                }
                total++;
            }
            i++;
            p = D_3660F8[i];
        } while (i < 10);
        if (ok != total) {
            if (s6[0x105] != 0 && *(s16 *)(arg1 + 0x86) != 0x13) {
                return 1;
            }
            if (*(s16 *)(arg1 + 0x7E) != 0 || arg1[0x7C] < arg0[0x7C]) {
                r = func_L01_00524598(arg0);
                if (r != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
