/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef struct Type1 Type1;
typedef struct { u8 prefix[0x10]; s16 f10[8]; s32 f20[8]; } SlotView;
void func_L01_00467288(Type1 *, s32, s32, s16);
void func_L01_004672A8(u8 *, s32);
void func_L01_004672D0(Type1 *a, s32 b, s32 i) {
    SlotView *p = (SlotView *)*(u8 **)((u8 *)a + 0xAC);
    func_L01_00467288(a, b, p->f20[i], p->f10[i]);
    func_L01_004672A8((u8 *)a, i);
}
