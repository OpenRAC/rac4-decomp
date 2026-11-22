/* cflags: @ee296 -O2 -G8 -fno-optimize-sibling-calls */
#include "common.h"
extern s32 func_L01_00466938(void *a, void *b, void *c);
s32 D_002218A0;
s32 D_002218A8;
void func_L01_004669C8(void *arg0) {
    func_L01_00466938((char *)*(void **)((char *)arg0 + 0xAC) + 0x60, &D_002218A0, &D_002218A8);
}
