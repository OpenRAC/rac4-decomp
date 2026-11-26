/* cflags: @ee296 -O2 -G0 -mno-split-addresses -falign-jumps=1 */
#include "common.h"

typedef struct {
    u8 pad0[0x7C];
    s32 f7C;
} A0T;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} A2T;

extern s32 func_01EE3960(void *arg0);
extern s32 func_01EE3A18(void *arg0, const u8 *arg1);
extern s32 func_01EE3AAC(void *arg0);
extern s32 func_01EE3AC0(void *arg0);
extern void func_01EF3318(void *arg0, const u8 *arg1, void *arg2);
extern void func_01F06988(s8 *arg0);
extern void func_01F0C090(char *arg0, s32 arg1);
extern u32 D_0016E3A8;
extern u8 D_0019DC20[];
extern u8 D_0019DC98[];
extern u8 D_0019DCB0[];
extern u8 D_0019DEC0[];
extern u8 D_0019DEC8[];

s32 func_01F029AC(A0T *arg0, s32 arg1, A2T *arg2) {
    u32 old;
    if (arg1 == 0 || arg2 == 0) {
        func_01F0C090((char *)D_0019DC20, 0x549);
        return 0;
    }
    old = D_0016E3A8++;
    arg2->f14 = old;
    arg2->fC = func_01EE3A18((void *)arg1, D_0019DC98);
    if (func_01EE3AC0((void *)arg1) == 0) {
        return 1;
    }
    if (func_01EE3AC0((void *)arg1) != 0) {
        arg2->f0 = func_01EE3AAC((void *)func_01EE3960((void *)arg1));
    } else {
        arg2->f0 = 0;
    }
    arg2->f4 = func_01EE3A18((void *)arg1, D_0019DEC0);
    if (arg0->f7C != 0) {
        arg2->f8 = func_01EE3A18((void *)arg1, D_0019DCB0);
    }
    if (arg2->f4 != 0) {
        func_01F06988((s8 *)arg2->f4);
    }
    arg2->fC = func_01EE3A18((void *)arg1, D_0019DC98);
    arg2->f10 = 0;
    func_01EF3318((void *)arg1, D_0019DEC8, &arg2->f10);
    return 1;
}
