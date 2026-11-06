/* cflags: -O2 -G8 -mno-split-addresses -malign-jumps=3 */
#include "common.h"

extern s32 D_001AF998[];

s32 func_01EA4570(u32 index) {
    u32 byte_offset = index * sizeof(s32);
    if (index >= 4) return 0;
    return *(s32 *)((u8 *)D_001AF998 + byte_offset);
}
