#include "common.h"

extern u8 D_00239640[];

s32 func_0044DF08(s32 arg0, u32 arg1, s64 arg2) {
    s32 base = (s32)D_00239640;
    s32 result;
    s64 value;

    if (D_00239640[0] != 0) {
        goto dispatch;
    }
    return 1;
dispatch:
    if (arg1 == 0x3D) {
        goto case28;
    }
    if (arg1 < 0x3E) {
        if (arg1 == 8) {
            goto case20;
        }
        if (arg1 < 9) {
            if (arg1 == 6) {
                goto case40;
            }
            result = 1;
            goto done;
        }
        if (arg1 == 0x14) {
            goto case38;
        }
        result = 1;
        goto done;
    }
    if (arg1 == 0x47) {
        goto case30;
    }
    if (arg1 < 0x48) {
        if (arg1 == 0x42) {
            goto case18;
        }
        result = 1;
        goto done;
    }
    if (arg1 == 0x4E) {
        goto case48;
    }
    result = 1;
    goto done;
case18:
    value = *(s64 *)(base + 0x18);
    if (value == arg2) {
        goto equal;
    }
    *(s64 *)(base + 0x18) = arg2;
    *(s32 *)(base + 0x4) = -1;
    goto success;
case30:
    value = *(s64 *)(base + 0x30);
    if (value == arg2) {
        goto equal;
    }
    *(s64 *)(base + 0x30) = arg2;
    *(s32 *)(base + 0x4) = -1;
    goto success;
case20:
    value = *(s64 *)(base + 0x20);
    if (value == arg2) {
        goto equal;
    }
    *(s64 *)(base + 0x20) = arg2;
    *(s32 *)(base + 0x8) = -1;
    goto success;
case40:
    value = *(s64 *)(base + 0x40);
    if (value != arg2) {
        goto update40;
    }
    goto equal;
equal:
    return 0;
update40:
    *(s64 *)(base + 0x40) = arg2;
    *(s32 *)(base + 0x10) = 0x7C;
    goto success;
case38:
    if (*(s64 *)(base + 0x38) == arg2) {
        goto equal;
    }
    *(s64 *)(base + 0x38) = arg2;
    goto success;
case48:
    value = *(s64 *)(base + 0x48);
    if (value == arg2) {
        goto equal;
    }
    *(s64 *)(base + 0x48) = arg2;
    goto success;
case28:
    value = *(s64 *)(base + 0x28);
    if (value == arg2) {
        goto equal;
    }
    *(s64 *)(base + 0x28) = arg2;
success:
    result = 1;
done:
    return result;
}
