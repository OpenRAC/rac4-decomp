/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u32 func_0011D480(void *buf, u32 size, u32 count, s32 fp);

/* Write arg2 bytes from arg1 to the file; return arg2 on success, else 0. */
s32 func_L00_0053BFA8(void *arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    if (*(s32 *)((u8 *)arg0 + 0xC) != 0 && arg1 != 0) {
        r = func_0011D480((void *)arg1, arg2, 1, *(s32 *)((u8 *)arg0 + 0x20)) != 0 ? arg2 : 0;
    }
    return r;
}
