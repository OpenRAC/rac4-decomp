/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct { u8 pad0[8]; s32 f8; } Node;
typedef struct {
    u8 pad0[0x10]; s32 f10; u8 pad14[0x80-0x14];
    Node *f80; u8 pad84[0xBC-0x84]; s32 fBC;
    u8 padC0[0xC4-0xC0]; s32 fC4; u8 padC8[0xCC-0xC8]; s32 fCC;
    u8 padD0[0xD4-0xD0]; s32 fD4;
} S;
extern s32 func_01EF0550(s32, s32);
s32 func_01F004CC(S *arg0) {
    s32 i, n;
    arg0->f10 = 0;
    i = 0;
    n = arg0->fC4;
    if (n > 0) {
        do {
            func_01EF0550(arg0->f80->f8, ((s32 *)arg0->fCC)[i]);
            i++;
            n = arg0->fC4;
        } while (i < n);
    }
    if (arg0->fC4 > 0) {
        func_01EF0550(arg0->f80->f8, arg0->fCC);
        arg0->fCC = 0;
        func_01EF0550(arg0->f80->f8, arg0->fD4);
        arg0->fD4 = 0;
        arg0->fC4 = 0;
        arg0->fBC = 0;
    }
    return 1;
}
