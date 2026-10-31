#include "common.h"

/* Clears the state, copies a 0x800-byte block to the scratchpad, then passes two words to the next stage. */
extern void func_00126E20(s32);
extern void func_004537D0(s32 *, s32 *, s32);
extern void func_00470B38(s32, s32);
extern u8 D_003D6860[];
extern s32 D_221310;
extern s32 D_00221318;

void func_0046D0C8(void) {
    func_00126E20(0);
    func_004537D0((s32 *)0x70003800, (s32 *)D_003D6860, 0x800);
    func_00470B38(D_221310, D_00221318);
}
