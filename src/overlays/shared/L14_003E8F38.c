#include "common.h"

extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005F1180(void *, void *);

// Spawn object 0x255B from the parent, setting its state to 1 and flag 0x100.
u8 *func_L14_003E8F38(void *parent) {
    u8 *object = func_L00_005DD000(0x255B, 0x80);
    if (object != 0) {
        func_L00_005F1180(object, parent);
        object[0x20] = 1;
        *(u16 *)(object + 0x34) |= 0x100;
    }
    return object;
}
