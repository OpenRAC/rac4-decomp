/* cflags: -Wuninitialized */
#include "common.h"
extern void func_L02_0049D260(void *);
extern void func_004493E8(void *, void (*)(void *), void *);
extern s32 D_0022251C;
void func_L02_0049D228(void *a) {
    *(u8 *)((u8 *)a + 48) = 0xFF;
    func_004493E8(&D_0022251C, func_L02_0049D260, a);
}
