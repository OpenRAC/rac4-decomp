#include "common.h"

/* Stores the 5-bit field of table entry arg0 - 1 through arg1 and returns 0; returns 0x80000004 when the index is out of range. */
typedef struct {
    u8 f0;
    u8 pad[0x10F];
} Type1;

typedef struct {
    u8 pad0[0x40];
    s32 f40;
    u8 pad1[0x64];
    Type1 fA8[1];
} Type2;

extern Type2 D_1BCC28;

s32 func_00154F18(s32 arg0, s16 *arg1) {
    s32 temp_a0;

    temp_a0 = arg0 - 1;
    if ((D_1BCC28.f40 < temp_a0) || (temp_a0 < 0)) {
        return 0x80000004;
    }
    *arg1 = ((u8 *)&D_1BCC28)[(((temp_a0 << 4) + temp_a0) << 4) + 0xA8] & 0x1F;
    return 0;
}
