#include "common.h"

typedef struct {
    u8 unknown0[0xD];
    u8 allowed[10];
    u8 unknown17[0x21];
} Definition;

extern const Definition *func_0054B050(s32);

s32 func_0054B628(s32 item, s32 mode)
{
    Definition definition;
    s32 i;

    definition = *func_0054B050(mode);
    for (i = 0; i < 10; i++) {
        if (definition.allowed[i] == item) {
            return 1;
        }
    }
    return 0;
}
