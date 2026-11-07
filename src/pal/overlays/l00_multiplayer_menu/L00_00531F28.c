/* cflags: -fno-schedule-insns */
#include "common.h"

s32 func_L00_00531F28(void *object, s32 *output) {
    s32 value = *(s32 *)((u8 *)object + 4);
    *output = value;
    return value != 0 ? 0 : 11;
}
