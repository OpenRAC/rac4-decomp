/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    u8 pad4[0xC];
    s32 f10;
    u8 pad14[0x9C];
    s32 *fB0;
    s32 fB4;
} Type1;

s32 func_01EE3A18(s32, s32 *);
void func_01EF382C(void);
void func_01F03E04(Type1 *);
void func_01F06988(s32);
extern s32 D_00170BB8[];
extern s32 D_0019E010[];

void func_01F03E40(Type1 *arg0)
{
    func_01EF382C();
    arg0->fB0 = D_00170BB8;
    func_01F03E04(arg0);
    arg0->fB4 = func_01EE3A18(arg0->f0, D_0019E010);
    if (arg0->fB4 != 0) {
        arg0->f10 = 1;
        func_01F06988(arg0->fB4);
    } else {
        arg0->f10 = 0;
    }
}
