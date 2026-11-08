#include "common.h"

extern u16 D_002218F0[];
extern u8 D_0015D250[];
s32 func_01ED72A0(void *, void *, s32);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
void func_0015B558(s32);
s32 func_0015B568(void);

/* PAL: from rac3-decomp's func_L39_006D5D68 */
s32 func_L00_00776038(u8 *arg0) {
    u16 buf[24];
    s32 ret = 1;
    if (arg0[0] != 0) {
        if (arg0[8] == 0) {
            buf[0] = D_002218F0[0];
            arg0[8] = ret;
            *(s32 *)(arg0 + 0xC) = func_0012FEB0(func_0012E370(), 0x24000);
            func_0015B558(func_01ED72A0(buf, D_0015D250, 0));
            if (func_0015B568() != 0) {
                ret = 0;
            }
        }
    }
    return ret;
}
