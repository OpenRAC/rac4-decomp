#include "common.h"

extern void func_00453718(s32, void *, s32);
extern s32 D_00222140;

void func_L00_005D3B70(s32 *arg0, s32 *arg1) {
    s32 size = *arg0 + 0x4000;
    D_00222140 = *arg1;
    *arg1 += size;
    func_00453718(D_00222140, arg0 + 4, size);
    *arg1 = (*arg1 + 0x3F) & 0xFFFFFFC0;
}
