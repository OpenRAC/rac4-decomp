#include "common.h"

extern void func_00502250(void *, s32, s32);
extern s32 func_0058F6D0(s32, s32, void *);
extern s32 func_005CD480(s32);
extern void func_00611880(s32 *, void *, s32);
extern s32 D_00172378[];
#define D_00172378 (D_00172378[0])

// Read a handle from the message and arm the linked +0xAC object with it.
void func_L41_003DDC08(u8 *object, s32 *msg) {
    u8 *target = *(u8 **)(object + 0xAC);
    s32 local;
    s32 h;

    if (!(*msg & 0xF) && object[0x20] != 2) {
        func_00611880(msg, &local, 4);
        h = func_005CD480(local);
        *(s32 *)(target + 0x8) = 1;
        *(s32 *)(target + 0x5C) = D_00172378;
        *(s32 *)(target + 0xC) = h;
        func_0058F6D0(0, 0, object);
        func_00502250(object, 2, -1);
    }
}
