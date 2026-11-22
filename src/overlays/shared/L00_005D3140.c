#include "common.h"

extern void func_004537D0(s32, s32, s32);
typedef struct {
    u8 pad[0x2B0];
    s32 count;
    u8 *tab;
} T1D;
extern T1D D_001D2200;

void func_L00_005D3140(s32 arg0, s32 arg1, s32 *arg2) {
    s32 i = 0;

    for (; i < D_001D2200.count; i++) {
        u8 *p = (u8 *)(i * 0x90 + (u32)D_001D2200.tab);
        s32 idx = *(s32 *)(p + 8);
        if (idx < 0) {
            *(s32 *)(p + 8) = 0;
        } else {
            s32 *e = (s32 *)((idx << 3) + arg0);
            s32 size = e[1];
            s32 o = e[0];
            *(s32 *)(p + 8) = *arg2;
            func_004537D0(*arg2, arg1 + o, size);
            e[0] = *arg2;
            *arg2 += size;
        }
    }
}
