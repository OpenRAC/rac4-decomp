#include "common.h"

extern s32 func_L14_005592F8(s32);
extern s32 func_L14_005593E8(s32, s32);
typedef struct { u8 pad0[0x10]; s16 f10; u8 pad12[0xC]; u8 f1E; u8 pad1F; } Type1;
extern s32 D_172160[];
extern Type1 *D_223188;
extern Type1 *D_2231E0[];

/* Finds a slot for (arg0, arg1), sets bit 2 of its byte at +0x1E, copies that byte to the other slots listed in D_2231E0, and sets their halfword at +0x10 to 0x7F80. */
void func_L14_005591A8(s32 arg0, s32 arg1)
{
    s32 idx;
    s32 i;

    idx = func_L14_005592F8(arg0);
    if (idx == -1) {
        idx = func_L14_005593E8(arg0, arg1);
    }
    if (idx >= 0) {
        D_223188[idx].f1E |= 4;
        if (D_172160[5] > 1) {
            s32 j;
            for (j = 1; j < D_172160[5]; j++) {
                D_2231E0[j][idx].f1E = D_223188[idx].f1E;
            }
        }
        D_223188[idx].f10 = 0x7F80;
        if (D_172160[5] > 1) {
            for (i = 1; i < D_172160[5]; i++) {
                D_2231E0[i][idx].f10 = 0x7F80;
            }
        }
    }
}
