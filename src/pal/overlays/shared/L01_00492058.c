/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

// Tests the data fields and the object's 0x04 flag.
s32 func_L01_00492058(void *object)
{
    s32 value;
    s32 result;
    void *data;

    data = *(void **)((u8 *)object + 0xAC);
    value = *(s32 *)((u8 *)data + 0x6C);
    if (value >= 0) {
        goto check_primary;
    }
    goto invalid_primary;
check_primary:
    if (value >= *(s32 *)((u8 *)data + 0x80)) {
        goto invalid_primary;
    }
    if (*(s32 *)((u8 *)data + 0x70) < 0) {
        goto success;
    }
    result = 0;
    if (*(s32 *)((u8 *)data + 0x84) <= 0) {
        goto done;
    }
success:
    return 1;
invalid_primary:
    if (*(s32 *)((u8 *)data + 0x70) < 0) {
        goto check_flag;
    }
    if (*(s32 *)((u8 *)data + 0x84) <= 0) {
        goto success;
    }
check_flag:
    result = 1;
    if (*(u8 *)((u8 *)object + 0xBE) & 4) {
        return result;
    }
    result = 0;
done:
    return result;
}
