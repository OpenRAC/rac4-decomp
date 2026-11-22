/* cflags: -fno-strength-reduce */
#include "common.h"

extern s32 D_0021DDB8;
extern s32 D_0021E724;
extern s32 D_0021E728;
extern s32 D_0021E72C;
extern s32 D_002443C0[];
extern s32 D_002444C0[];

void func_L00_005F1620(void) {
    s32 a = D_0021DDB8;
    s32 n;
    s32 i;

    if (a != D_0021E72C) {
        n = D_0021E728;
        D_0021E72C = a;
        D_0021E724 = 0;
        if (n > 0) {
            s32 c = n;
            i = 0;
            do {
                D_002443C0[i] = D_002444C0[i];
                i++;
                c--;
            } while (c != 0);
            D_0021E724 = i;
        }
        D_0021E728 = 0;
    }
}
