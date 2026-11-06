#include "common.h"

typedef struct Record {
    u8 unknown00[0x3C];
    s32 previous;
    s32 current;
} Record;

extern Record *func_0054BF00(s32 type);

void func_004C0038(s32 selection, s32 *current, s32 *previous)
{
    s32 type;
    Record *record;

    *current = 0;
    *previous = -1;
    type = selection;
    selection = -1;
    switch (type) {
    case 0:
        selection = 2;
        break;
    case 1:
        selection = 3;
        break;
    case 2:
        selection = 4;
        break;
    case 3:
        selection = 5;
        break;
    case 4:
        selection = 6;
        break;
    }
    if (selection != -1) {
        record = func_0054BF00(selection);
        *current = record->current;
        *previous = record->previous;
    }
}
