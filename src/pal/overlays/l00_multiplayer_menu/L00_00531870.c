/* cflags: -fno-schedule-insns */
#include "common.h"

s32 func_L00_00531870(void *object, s32 *output) {
    s32 value = *(s32 *)((u8 *)object + 12);
    *output = value;
    return value != 0 ? 0 : 11;
}
