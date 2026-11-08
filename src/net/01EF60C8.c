/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses -Wa,-G0 */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0xA0];
    s32 fA0;
    u8 padA4[0x10];
    f32 fB4;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
    s32 fCC;
} Type1;

void func_01EEDCD0(void *, s32 *, s32);
extern s32 D_0019CA28[];

void func_01EF60C8(Type1 *arg0)
{
    func_01EEDCD0((u8 *)arg0 + 0x38, D_0019CA28, 0x40);
    arg0->fB4 = 100000.0f;
    arg0->fB8 = 2;
    arg0->fBC = 0;
    arg0->fA0 = 0;
    arg0->fC0 = 0;
    arg0->fC4 = 0;
    arg0->fC8 = 0;
    arg0->fCC = 0;
}
