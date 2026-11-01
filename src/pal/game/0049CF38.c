#include "common.h"

typedef struct {
    u8 pad00[0x24];
    u8 flag24;
    u8 pad25[0xF];
} Record;

extern Record D_0030702C[];
extern u8 D_003071D8[];

void func_0049CF38(s32 kind, s32 index)
{
    Record *record;

    if (kind == 4) {
        record = &D_0030702C[index];
    } else {
        record = (Record *)(D_003071D8 + (kind << 9)) + index;
    }
    record->flag24 = 1;
}
