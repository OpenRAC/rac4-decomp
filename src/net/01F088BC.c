/* cflags: -O2 -G8 -mno-split-addresses -Wuninitialized */
#include "common.h"

void func_01F088BC(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x8B7C) = arg1;
}
