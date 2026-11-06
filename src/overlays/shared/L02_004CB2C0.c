/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

s32 func_L02_004CB2C0(void *arg0) {
    void *temp_4;
    temp_4 = *(void **)((u8 *)arg0 + 0xAC);
    if (*(s32 *)((u8 *)*(void **)((u8 *)temp_4 + 0x170) + 0x2B8) != 0) {
        return *(u8 *)((u8 *)temp_4 + 0x211) != 0;
    }
    return 0;
}
