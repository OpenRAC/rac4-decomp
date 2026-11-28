#include "common.h"
#include "pal/menu_options.h"

typedef struct {
    u8 pad00[0x20];
    u16 f20[3];
    u8 pad26[2];
    s32 f28[11];
} MenuOptionMixedValues;

s32 func_L00_00710440(s32 index, const MenuOptionMixedValues *values)
{
    const s32 *word = NULL;
    const u16 *half = NULL;
    s32 result;

    switch (D_L00_004B7310[index].kind) {
    case 2:
        half = &values->f20[1];
        break;
    case 3:
        half = &values->f20[2];
        break;
    case 4:
        word = &values->f28[0];
        break;
    case 5:
        word = &values->f28[1];
        break;
    case 6:
        word = &values->f28[2];
        break;
    case 7:
        word = &values->f28[3];
        break;
    case 8:
        word = &values->f28[4];
        break;
    case 9:
        word = &values->f28[5];
        break;
    case 11:
        word = &values->f28[6];
        break;
    case 12:
        word = &values->f28[7];
        break;
    case 13:
        word = &values->f28[8];
        break;
    case 14:
        word = &values->f28[9];
        break;
    case 15:
        word = &values->f28[10];
        break;
    case 1:
        half = &values->f20[0];
        break;
    }
    result = 0;
    if (word != NULL)
        result = func_L00_007102B0(index, *word);
    else if (half != NULL)
        result = func_L00_007102B0(index, *half);
    return result;
}
