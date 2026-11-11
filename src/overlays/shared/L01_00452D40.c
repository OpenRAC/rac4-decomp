#include "common.h"

extern s32 func_004534D0(void *);
extern void func_0046BDD0(void *);
extern void func_00473A88(void *, s32, s32);
extern void func_L01_00452E10(void *);
extern void func_L01_00453100(void *);
extern void func_L01_00453608(void *);

void func_L01_00452D40(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    if (vars != NULL && *(s32 *)(vars + 0x10) != 0) {
        switch (arg0[0x20]) {
        case 0: {
            s32 first;
            u8 flags = arg0[0xBE];
            if ((flags ^ 1) & 1) {
                first = 1;
                arg0[0xBE] = flags | 1;
            } else {
                first = 0;
            }
            if (first != 0) {
                *(s32 *)(vars + 0x14) = 0x3C;
            }
            func_L01_00452E10(arg0);
            func_L01_00453608(arg0);
            func_L01_00453100(arg0);
            if (func_004534D0(vars + 0x14) != 0) {
                func_00473A88(arg0, 1, -1);
            }
            break;
        }
        case 1:
            func_0046BDD0(arg0);
            break;
        }
    }
}
