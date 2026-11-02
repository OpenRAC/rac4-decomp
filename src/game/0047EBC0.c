#include "common.h"

void *func_00510BE8(s32);

// Store value in the +0x31E0 word of the object func_00510BE8 returns, unless
// the object is missing, value is zero or its +0x25CC word is 0x66.
void func_0047EBC0(s32 index, s32 value) {
    u8 *object = func_00510BE8(index);
    if (object != 0 && value != 0 && *(s32 *)(object + 0x25CC) != 0x66) {
        *(s32 *)(object + 0x31E0) = value;
    }
}
