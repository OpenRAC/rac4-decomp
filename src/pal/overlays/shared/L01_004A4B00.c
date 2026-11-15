/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
/* Word at this address is read here; its enclosing allocation is not yet known. */
extern int D_001DFD20[];
extern void func_004628C0(s32);
void func_L01_004A4B00(void *arg0, s32 arg1) {
    void *p = *(void **)((u8 *)arg0 + 0xAC);
    if (D_001DFD20[0] != arg1) func_004628C0(arg1);
    *(s8 *)((u8 *)p + 0x684) = arg1;
}
