/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void func_00474368(void *, s32, s32);
extern void func_L06_004C8C28(void *, s32, s32);
extern void func_L06_004C8DF8(void *);
void func_L06_004C8BB0(void *arg0)
{
    u8 *owner = *(u8 **)((u8 *)arg0 + 0xAC);
    *(u16 *)((u8 *)arg0 + 0x34) |= 1;
    *(s32 *)(owner + 0x54) = 1;
    *(f32 *)(owner + 0x50) = 1.0f;
    if (*(u8 *)(owner + 0xEC))
        *(u8 *)(owner + 0xED) = 0;
    func_L06_004C8C28(arg0, *(u8 *)(owner + 0xEC), *(u8 *)(owner + 0xED));
    func_L06_004C8DF8(arg0);
    func_00474368(arg0, 1, -1);
}
