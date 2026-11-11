#include "common.h"

typedef struct {
    u8 unknown0[0xD];
    u8 allowed[10];
    u8 unknown17[0x21];
} Definition;

extern const Definition *func_00549AE8(s32);

s32 func_0054A0C0(s32 item, s32 mode)
{
    Definition definition;
    s32 i;

    definition = *func_00549AE8(mode);
    for (i = 0; i < 10; i++) {
        if (definition.allowed[i] == item) {
            return 1;
        }
    }
    return 0;
}
