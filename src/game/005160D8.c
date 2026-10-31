#include "common.h"

extern u8 D_00172160[];
extern s32 D_212138[];
extern s32 func_0054AFB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_01E9E270(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, void *t1);

/* Passes a flag byte from the device block to func_01E9E270 when its word at 0x258 is zero, then calls func_0054AFB8 with the same byte's address. */
void func_005160D8(void *arg0) {
    u8 local;
    u8 *dev;

    dev = D_00172160;
    local = *(u8 *)((u8 *) arg0 + 0x2F10);
    if (*(s32 *)(dev + 0x258) == 0) {
        func_01E9E270(*(u8 *)(dev + 0x7F8) | 0x40, *(s32 *)(dev + 0x8), -1, D_212138[0], 1, &local);
    }
    func_0054AFB8(0, 0, 0, (s32) &local);
}
