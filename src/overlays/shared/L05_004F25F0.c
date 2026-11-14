/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_L01_00550790(s32 unused0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8A28(u8 *obj);
extern s32 D_222920[];

/* Clear the flags on the object at arg0+0xAC, run the setup calls on it, then set the state and call 00591BD8. */
void func_L05_004F25F0(u8 *arg0) {
    u8 *s0 = *(u8 **)(arg0 + 0xAC);
    u8 *p;
    u8 *q;
    u8 *t;

    s0[0x47D] = 0;
    *(s32 *)(s0 + 0x470) = 0;
    s0[0x47E] = 0xFF;
    func_L01_005A8A28(arg0);
    p = *(u8 **)(s0 + 0x450);
    *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) & 0xFFBE;
    q = *(u8 **)(s0 + 0x450);
    *(u16 *)(q + 0x34) = *(u16 *)(q + 0x34) | (*(u16 *)(*(u8 **)(q + 0x24) + 0x44) & 0x1000);
    t = *(u8 **)(s0 + 0x450);
    *(s32 *)(t + 0x98) = *(s32 *)(*(u8 **)(t + 0x24) + 0x10);
    func_L01_00591BD8(arg0, 1, 1);
    func_L01_00550790((s32)D_222920, (s32)arg0, (s32)(arg0 + 0x10), (s32)(arg0 + 0xF0), (s32)(s0 + 0x450), 1, 0);
}
