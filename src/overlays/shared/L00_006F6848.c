#include "common.h"

extern s32 D_00172378[];
extern void *D_00222478;
extern void *func_006AA550(void *, void *, void *);

void func_L00_006F6848(u8 *arg0) {
    void *a1 = *(void **)(arg0 + 0x10);
    void *a2;
    void *v0;

    if (a1 == 0) {
        return;
    }
    a2 = *(void **)(arg0 + 0x14);
    if (a2 == 0) {
        return;
    }
    if (D_00172378[0] <= *(s32 *)(arg0 + 0x18) + 0x104) {
        return;
    }
    if (*(s32 *)((u8 *)a1 + 0x28) != 0 || a1 == D_00222478) {
        ((void (*)(void *, s32))a2)(a1, 0);
        return;
    }
    v0 = func_006AA550(a1, a1, a2);
    if (v0 != 0 && *(u8 *)((u8 *)v0 + 0x2C) != 0) {
        ((void (*)(void *, s32))*(void **)(arg0 + 0x14))(*(void **)(arg0 + 0x10), 0);
    }
}
