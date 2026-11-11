#include "common.h"
/* Ported from rac3-decomp's func_L39_006DE688 (src/levels/39_multiplayer_menu/L39_006DC228.c, GPL-3.0), the same code in both games. */

void func_L00_005C17B0(void *, void *, s32);
void func_L00_0077CBA8(s32 arg0, s32 arg1);
void func_L00_0077C958(u8 *s) {
    u8 key[0x100];
    u8 val[0x100];
    u8 *p;
    u8 *q;
    s32 n;
    s32 m;
    p = s + 0x19;
    q = p;
    do {
        n = 0;
        while (p - s < 1000 && (*p == ' ' || *p == '\n' || *p == '\t')) {
            p++;
        }
        for (; q - s < 1000 && *q != 0; q++) {
            if (*q == '=' || *q == ' ' || *q == '\t') {
                n = q - p;
                if (n >= 0x100) {
                    n = 0xFF;
                }
                func_L00_005C17B0(key, p, n);
                key[n] = 0;
                while (q - s < 1000 && (*q == ' ' || *q == '=' || *q == '\t')) {
                    q++;
                }
                p = q;
                break;
            }
        }
        if (n == 0) {
            return;
        }
        m = 0;
        for (; p - s < 1000 && *p != 0; p++) {
            if (*p == '\n' || p - s == 999) {
                m = p - q;
                if (m >= 0x100) {
                    m = 0xFF;
                }
                func_L00_005C17B0(val, q, m);
                val[m] = 0;
                func_L00_0077CBA8((s32)key, (s32)val);
                while (p - s < 1000 && (*p == ' ' || *p == '\n')) {
                    p++;
                }
                q = p;
                break;
            }
        }
    } while (m != 0);
}
