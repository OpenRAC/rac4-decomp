#include "common.h"
extern void func_L01_00495838();
extern void func_L01_00494FE0(void *);
extern void func_L01_005A8A28(void *);
extern void func_00473A88(void *, s32, s32);
void func_L01_00494F80(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0xAC);
    *(s16 *)(p + 0x4D6) = -1;
    p[0x4D8] = 0;
    p[0x4D9] = 0;
    p[0x485] = 0;
    func_L01_00495838();
    func_L01_00494FE0(arg0);
    func_L01_005A8A28(arg0);
    func_00473A88(arg0, 2, 2);
}
