#include "common.h"

extern u8 *D_00222694;
extern void *func_L00_005DEBD0(s32, s32, s32);

s32 func_L15_004ADB68(u8 *arg0) {
    u8 *block = *(u8 **)(arg0 + 0xAC);
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 id = *(s32 *)(block + 0x70 + i * 4);
        u8 *entry;
        void *cb;
        if (id == -1) continue;
        entry = D_00222694 + (id << 8);
        cb = func_L00_005DEBD0(*(s16 *)(entry + 0xBC), 0x14, 8);
        if (cb == 0 || ((void **)cb)[1] == 0) continue;
        if (((s32 (*)(void *))((void **)cb)[1])(entry) == 0) return 0;
    }
    return 1;
}
