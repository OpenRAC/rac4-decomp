#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 *func_L00_005DD000(s32, s32);
extern s32 func_L00_005FE300(void *, s32);
extern void func_L01_004ADB78(void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8A28(u8 *obj);

/* Spawn the linked +0x610 object (kind by +0xBC), set it up, then enter state 1. */
void func_L01_004AD9F8(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);
    s32 *v;

    if (*(s16 *)(object + 0xBC) == 0x2756) {
        *(u8 **)(linked + 0x610) = func_L00_005DD000(0x2757, 0);
    } else {
        *(u8 **)(linked + 0x610) = func_L00_005DD000(0x24B3, 0);
    }
    if (*(u8 **)(linked + 0x610) != 0) {
        *(u16 *)(*(u8 **)(linked + 0x610) + 0x34) |= 0x100;
        v = (s32 *)(*(u8 **)(linked + 0x610) + 0xF0);
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;
        *(u16 *)(*(u8 **)(linked + 0x610) + 0x32) = *(u16 *)(object + 0x32);
        *(u8 **)(*(u8 **)(linked + 0x610) + 0xB8) = object;
    }
    func_L01_005A8A28(object);
    func_L01_004ADB78(object);
    func_L00_005FE300(object, 0);
    *(u128 *)(linked + 0x600) = *(u128 *)(object + 0x10);
    func_L01_00591BD8(object, 1, 0);
}
