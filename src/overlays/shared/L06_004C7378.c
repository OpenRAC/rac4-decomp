/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void func_0053C1C8(void *, s32, s32);
extern void func_004C73F0(void *, s32, s32);
extern void func_004C75C0(void *);
void func_L06_004C7378(void *arg0)
{
    u8 *owner = *(u8 **)((u8 *)arg0 + 0xAC);
    *(u16 *)((u8 *)arg0 + 0x34) |= 1;
    *(s32 *)(owner + 0x54) = 1;
    *(f32 *)(owner + 0x50) = 1.0f;
    if (*(u8 *)(owner + 0xEC))
        *(u8 *)(owner + 0xED) = 0;
    func_004C73F0(arg0, *(u8 *)(owner + 0xEC), *(u8 *)(owner + 0xED));
    func_004C75C0(arg0);
    func_0053C1C8(arg0, 1, -1);
}
