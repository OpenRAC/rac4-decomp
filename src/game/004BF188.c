#include "common.h"

typedef struct Item {
    u8 prefix[0x38];
    s32 value;
} Item;

extern Item *func_0054A998(s32 type);

s32 func_004BF188(s32 selection)
{
    s32 type;
    s32 value = 0;

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
        value = func_0054A998(selection)->value;
    }
    return value;
}
