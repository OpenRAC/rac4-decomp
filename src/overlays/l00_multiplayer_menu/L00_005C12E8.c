#include "common.h"

extern s16 func_L00_005C1290(s32 arg0);
extern s32 D_0021E5C4;
u8 D_0021E5BC = 0;
s32 D_0021E5B8 = 0;
s32 D_0021E5CC = 0;
s32 D_0021E5C8 = 0;

/* Finds the first position at or after D_0021E5C4 where arg0 occurs in the text; returns it, or 0x20 if none. */
s32 func_L00_005C12E8(s16 arg0) {
    s32 lim;
    s32 a1;
    s32 s0;
    s32 s1;
    s32 m1 = -1;
    s32 s3;
    s32 t;
    if (D_0021E5BC == 0) {
        return arg0 & 0xFF;
    }
    s3 = m1;
    a1 = 0;
    lim = (D_0021E5B8 < D_0021E5CC) ? D_0021E5B8 : D_0021E5CC;
    s1 = D_0021E5C4;
    if (lim > 0) {
        do {
            s3 = ((a1 ^ arg0) == 0) ? arg0 : s3;
            a1++;
        } while (s3 < 0 && a1 < lim);
    }
    s0 = lim;
    if (s3 < 0 && s0 < D_0021E5B8) {
        do {
            t = func_L00_005C1290(s0);
            if ((t & 0xFFFF) >= D_0021E5CC) {
                switch (s1 & 0xFF) {
                case 0:
                case 0x25:
                case 0x5C:
                    s1++;
                    break;
                }
                if (t == arg0) {
                    s3 = s1 + D_0021E5C8;
                }
                s1++;
            }
            s0++;
        } while (s3 < 0 && s0 < D_0021E5B8);
    }
    return (m1 < s3) ? s3 : 0x20;
}
