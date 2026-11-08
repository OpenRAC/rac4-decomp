#include "common.h"

/* Landing note: D_00220E7C is defined in src/pal/game/00540FA8.c; this function belongs in that file. */
s32 D_00220E7C = 0;
extern void *func_0053DCD0(s32, s32, s32, s32);
extern void func_0053DE58(void *, void *, s32);

/* PAL: from rac3-decomp's func_L39_0066DC28 */
void func_00541DF0(s32 *a0, u8 a1, u8 a2) {
    u8 byte[16];
    s32 word[4];
    void *context;

    context = func_0053DCD0(D_00220E7C, 2, 0, 0);
    *(s32 *)((u8 *)context + 0x50) = a0[18];
    word[0] = a0[0];
    func_0053DE58(context, word, 4);
    byte[0] = a1;
    func_0053DE58(context, byte, 1);
    byte[0] = a2;
    func_0053DE58(context, byte, 1);
}
