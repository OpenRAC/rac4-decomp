#include "common.h"

extern s32 func_L00_005E60D0(s32, s32);
extern void func_L00_0066CCE8(void *, s32);
extern s32 func_L00_0066D220(s32, s32, void *);
extern s32 func_L08_004B80D8(u8 *arg0, s32 arg1);

// Counts set flag bits, picks the Nth one and clears it, then notifies.
void func_L08_004B72E8(u8 *arg0) {
    s32 cnt;
    s32 *s1;
    s32 i;
    s32 j;
    s32 r;
    s32 sel;
    s32 n;
    s32 v;

    if (arg0[0x20] < 8) {
        s1 = *(s32 **)(arg0 + 0xAC);
        cnt = 0;
        for (i = 0; i < 6; i++) {
            cnt += (s1[3] >> i) & 1;
        }
        if (((cnt - 1) & 1) == 0) {
            func_L00_0066CCE8(arg0, 1);
            v = 3 - cnt / 2;
            s1[0x340 / 4] = v;
            func_L00_0066D220(v, 4, arg0);
        }
        r = func_L00_005E60D0(0, cnt);
        n = 0;
        sel = 0;
        for (j = 0; j < 6; j++) {
            if ((s1[3] >> j) & 1) {
                if (n == r) {
                    s1[3] &= ~(1 << j);
                    sel = j;
                    break;
                }
                n++;
            }
        }
        func_L08_004B80D8(arg0, sel);
    }
}
