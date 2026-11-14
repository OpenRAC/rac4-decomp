#include "common.h"

extern void func_01EEFB78();
extern s32 D_0021DF68;
extern s32 D_00220CF0[];

/* Reset three flag bytes when the channel is set. */
void func_L00_0071A010(u8 *arg0) {
    if (D_0021DF68 != 0) {
        func_01EEFB78(D_00220CF0);
        arg0[0x5C] = 0;
        arg0[0x5D] = 0;
        arg0[0x5E] = 0;
    }
}
