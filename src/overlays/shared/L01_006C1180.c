#include "common.h"

extern u8 *func_006C1020();
extern s32 func_L00_00702698();
extern s32 func_L00_007027E8();
extern s32 D_0021EBD8;
extern s32 D_0021DE10;
extern u32 D_171C08[];

// Check whether the current entry is eligible and matches the slot and value in the current cycle.
s32 func_L01_006C1180(void) {
    u8 *p;
    s32 id;
    s32 a;
    s32 r;
    s32 st;

    p = func_006C1020();
    id = *(s32 *)p;
    if (id == -1 || (*(u32 *)((u32)D_171C08 + (((u32)id >> 5) << 2)) & (1 << (id & 0x1F))) || func_L00_007027E8(p + 0xC) == 0) {
fail:
        return 0;
    }
    st = D_0021DE10;
    if (*(s32 *)(p + 8) != 0 && st != 1 && st != 0x15) {
        goto fail;
    }
    if (*(s32 *)(p + 0x1C) == 0) {
        return 1;
    }
    r = func_L00_00702698(*(s32 *)(p + 0x1C), &a);
    if ((a - 1) % 20 != (D_0021DE10 - 1) % 20) {
        goto fail;
    }
    if (D_0021EBD8 != r) {
        goto fail;
    }
    return 1;
}
