#include "common.h"

extern void func_007107C0();
extern s32 D_004B9E90[];

/* resets a menu object: clears a word table and sets defaults */
void func_L00_0071AF88(void *arg0, s32 arg1) {
    s32 i;
    s32 *p;
    *(s32 *)((u8 *)arg0 + 0xAC) = 0;
    *(s32 **)((u8 *)arg0 + 0x58) = D_004B9E90;
    p = (s32 *)((u8 *)arg0 + 0x22C);
    for (i = 0x5F; i >= 0; i--) {
        *p = 0;
        p = (s32 *)((u8 *)p - 4);
    }
    *(s32 *)((u8 *)arg0 + 0x230) = -1;
    func_007107C0(arg0, arg1);
}
