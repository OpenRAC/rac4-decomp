#include "common.h"

extern s32 func_0050BFA8(void *, void *);

// Copies the float at 0x44 and the words at 0x48 and 0x4C from arg1 into arg0, once arg1's check at vtable slot 0x14 passes.
s32 func_005109A8(void *arg0, void *arg1) {
    s32 (*check)(void *, s32);

    check = *(s32 (**)(void *, s32))((u8 *)*(void **)((u8 *)arg1 + 0x8) + 0x14);
    if (check(arg1, 1) != 0) {
        func_0050BFA8(arg0, arg1);
        *(f32 *)((u8 *)arg0 + 0x44) = *(f32 *)((u8 *)arg1 + 0x44);
        *(s32 *)((u8 *)arg0 + 0x48) = *(s32 *)((u8 *)arg1 + 0x48);
        *(s32 *)((u8 *)arg0 + 0x4C) = *(s32 *)((u8 *)arg1 + 0x4C);
        return 1;
    }
    return 0;
}
