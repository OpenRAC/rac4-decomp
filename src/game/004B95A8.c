#include "common.h"

extern s32 func_004A09E8();
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32, f32, f32);
extern s32 func_00504E68(s32 handle, float *a, float *b);
extern void func_00504F68(s32, s32);
extern s32 func_00505040(u32 id, s32 enabled);
extern void func_00505328(s32, s32);
extern s32 func_005058E0(u32, f32, f32);
extern s32 func_00505DD0(u32 id, s32 amount);
extern f32 D_003D1E00[];
extern s32 D_002217B0;

/* Creates 13 objects at the positions in D_003D1E00 and registers them. */
void func_004B95A8(void) {
    s32 i;
    f32 *pos;
    s32 h;

    i = 0;
    pos = D_003D1E00;
    do {
        h = func_004A1A60(&D_002217B0, i + 0xB4);
        func_004A09E8(h);
        func_00504238(h, pos[0], pos[1]);
        pos += 2;
        func_005058E0(h, 0.8f, 0.8f);
        func_00505040(h, 1);
        func_00504F68(h, 1);
        func_00504E68(h, (float *)(i <= 4 ? 2 : 1), (float *)3);
        func_00505328(h, 0x80D0D0D0);
        func_00505DD0(D_002217B0, h);
        i++;
    } while (i < 13);
}
