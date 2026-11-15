#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0011AB04(u8 *);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern void func_L00_0076E478(u8 *arg0, s32 arg1);
extern u8 *D_002233A4;

/* Clears the object's name block, stores the name and four settings, and starts state 3. */
void func_L00_0076DDD8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 *p;

    p = *(s32 **)(D_002233A4 + 0x34);
    func_0011A518(arg0 + 0x20, 0, 0xAC);
    func_L00_005C1758((s32)(arg0 + 0x20), (s32)arg1, func_0011AB04(arg1));
    *(s32 *)(arg0 + 0xBC) = *p;
    *(s32 *)(arg0 + 0x14) = arg2;
    *(s32 *)(arg0 + 0x18) = arg3;
    *(s32 *)(arg0 + 0xCC) = arg4;
    *(s32 *)(arg0 + 0xD0) = arg5;
    func_L00_0076E478(arg0, 3);
}
