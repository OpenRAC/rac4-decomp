/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_L00_007167F8(void *object) {
    s32 value = *(s32 *)((u8 *)object + 0xB78);
    if (value == 0) {
        return (s32)((u8 *)object + 0xB7C);
    }
    return value;
}
