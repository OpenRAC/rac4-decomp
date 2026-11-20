/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern s32 func_L00_00546108(u32 offset, void *arg4, void *arg5);
s32 func_L00_00534670(u32 *start, u32 *end, u32 *base, void *arg4, void *arg5) {
    while ((s32)start < (s32)end) {
        if (func_L00_00546108((u32)start - (u32)base, arg4, arg5) > 0) {
            u32 value = *start;
            *start = (((s32)value >> 13) & 0x7FFFF) | ((value << 19) & 0xFFF80000);
        }
        start++;
    }
    return 0;
}
