/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Type1;
extern void func_01EB4D28(u8 *p, u32 x);
extern s32 func_01E9CE80(void *a, void *b, s32 c, s32 d, s32 e, s32 *f, u8 *g, u32 h, s32 i);
extern s32 D_001694FC[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];

/* Gated call: if the flag is set and the arguments are valid, runs the helper and stores its result. */
s32 func_01EB5458(s32 a0, Type1 a1, u32 a2, s32 a3, s32 a4, s32 *a5)
{
    u8 sp20[16];
    s32 sp30;
    u8 *p;
    s32 x;
    s32 temp_v0;

    x = a1.f0;
    sp30 = 0;
    if (D_001694FC[0] == 0) {
        return 5;
    }
    if (a0 < 0) {
        return 2;
    }
    if (x == 0) {
        return 2;
    }
    if (a2 & 0xFFFF0000) {
        return 2;
    }
    p = sp20;
    a5[0] = 0;
    func_01EB4D28(p, x);
    temp_v0 = func_01E9CE80(D_1B26C0, D_1B2700, a0, a3, a4, &sp30, p, a2, 0);
    if (temp_v0 < 0) {
        return 0xC350;
    }
    a5[0] = temp_v0;
    return 0;
}
