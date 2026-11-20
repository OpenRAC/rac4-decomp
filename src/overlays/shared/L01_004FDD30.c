#include "common.h"

extern void func_L00_005B0038(void *, void *, s32);
extern s32 func_L01_004FDCE0();
extern void func_L01_004FDE88(void);
extern s32 D_222A98;

void func_L01_004FDD30(s32 arg0, u8 *arg1) {
    u8 v;
    u8 *p;

    if (func_L01_004FDCE0(arg0) != 0) {
        if (arg1[0x26E] != 0) {
            arg1[0x26E]--;
            p = arg1 + 0x282;
            do {
                v = *p;
                if (v != 0) {
                    *p = v - 1;
                }
                p++;
            } while ((s32)p < (s32)(arg1 + 0x284));
        }
        func_L00_005B0038(&D_222A98, func_L01_004FDE88, arg0);
    }
}
