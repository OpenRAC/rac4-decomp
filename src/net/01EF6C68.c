/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x18];
    f32 f18;
    f32 f1C;
    u8 pad20[0xC];
    s32 f2C;
    u8 pad30[0x84];
    f32 fB4;
    f32 fB8;
    f32 fBC;
} Type1;

void func_01EEDCD0(void *, s32 *, s32);
extern s32 D_0019CC58[];

void func_01EF6C68(Type1 *arg0)
{
    func_01EEDCD0((u8 *)arg0 + 0x38, D_0019CC58, 0x40);
    arg0->fB4 = arg0->f18;
    arg0->fB8 = arg0->f1C;
    arg0->fBC = 2.0f;
    arg0->f2C = -1;
}
