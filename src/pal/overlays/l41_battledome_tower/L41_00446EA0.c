#include "common.h"

s32 func_L41_00446EA0(void *object, s32 identifier) {
    s32 *table = *(s32 **)((u8 *)object + 0xAC);
    s32 result = 0;
    s32 slot = -1;
    s32 index;

    for (index = 0; index < 16; ++index) {
        s32 value = table[index];
        if (value == identifier) {
            return 1;
        }
        if (value == -1) {
            if (slot == -1) {
                slot = index;
            }
        }
    }
    if (slot != -1) {
        s32 *entry = table + slot;
        result = 1;
        *entry = identifier;
    }
    return result;
}
