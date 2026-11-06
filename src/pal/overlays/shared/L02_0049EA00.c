/* cflags: -Wuninitialized */
#include "common.h"
extern void func_L02_0049EA38(void *);
extern void func_00449A28(void *, void (*)(void *), void *);
extern s32 D_0022261C;
void func_L02_0049EA00(void *a) {
    *(u8 *)((u8 *)a + 48) = 0xFF;
    func_00449A28(&D_0022261C, func_L02_0049EA38, a);
}
