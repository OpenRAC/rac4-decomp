/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

unsigned char func_L01_005B4F70(int, int);
void func_L01_00591BD8(u8 *, s32, s32);

s32 func_L01_004BA750(void *arg0, s32 arg1) {
    void *state = *(void **)((u8 *)arg0 + 0xAC);
    if (arg1 == 4) {
        *(s16 *)((u8 *)state + 0x5EA) = -1;
        *(s8 *)((u8 *)state + 0x611) = 1;
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        func_L01_005B4F70((s32)arg0, 0);
        func_L01_00591BD8(arg0, 2, 2);
    }
    return 1;
}
