#include "common.h"
#include "pal/menu_options.h"

s32 func_L00_00710538(s32 index, const MenuOptionValues *values)
{
    const s32 *field = NULL;
    s32 result;
    switch (D_L00_004B7310[index].kind) {
    case 2:
        field = &values->f148[0];
        break;
    case 3:
        field = &values->f148[1];
        break;
    case 4:
        field = &values->f148[2];
        break;
    case 5:
        field = &values->f148[3];
        break;
    case 6:
        field = &values->f148[4];
        break;
    case 7:
        field = &values->f148[5];
        break;
    case 8:
        field = &values->f148[6];
        break;
    case 9:
        field = &values->f148[7];
        break;
    case 11:
        field = &values->f148[8];
        break;
    case 12:
        field = &values->f148[9];
        break;
    case 13:
        field = &values->f148[10];
        break;
    case 14:
        field = &values->f148[11];
        break;
    case 15:
        field = &values->f148[12];
        break;
    case 1:
        field = &values->f04;
        break;
    }
    result = 0;
    if (field != NULL)
        result = func_L00_007102B0(index, *field);
    return result;
}
