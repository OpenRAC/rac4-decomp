/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* Clear or set bit 29 on the nested object's word. */
void func_L01_004ED190(void *arg0, s32 arg1) {
    void *object;

    object = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xAC) + 0x2E0);
    if (arg1 != 0) {
        *(s32 *)((u8 *)object + 0x2D8) = (s32)(*(s32 *)((u8 *)object + 0x2D8) & 0xDFFFFFFF);
        return;
    }
    *(s32 *)((u8 *)object + 0x2D8) = (s32)(*(s32 *)((u8 *)object + 0x2D8) | 0x20000000);
}
