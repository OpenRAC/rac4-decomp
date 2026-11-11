#include "common.h"

extern void func_007690F8(s32);
extern u8 *D_002233A4;

s32 func_L00_007274E0(u8 *arg0) {
    func_007690F8(*(s32 *)(D_002233A4 + 0x3C));
    arg0[0x260] = 1;
    return 1;
}
