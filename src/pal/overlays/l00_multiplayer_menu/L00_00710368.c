#include "common.h"
#include "pal/menu_options.h"

s32 func_L00_00710368(s32 index, const MenuOptionValues *values)
{
    const s32 *field = NULL;
    s32 result;
    switch (D_L00_004B7310[index].kind) {
    case 2:
        field = &values->f20[0];
        break;
    case 3:
        field = &values->f20[1];
        break;
    case 4:
        field = &values->f20[2];
        break;
    case 5:
        field = &values->f20[3];
        break;
    case 6:
        field = &values->f148[11];
        break;
    case 7:
        field = &values->f148[12];
        break;
    case 8:
        field = &values->f148[13];
        break;
    case 9:
        field = &values->f148[14];
        break;
    case 11:
        field = &values->f148[15];
        break;
    case 12:
        field = &values->f148[16];
        break;
    case 13:
        field = &values->f148[17];
        break;
    case 14:
        field = &values->f148[18];
        break;
    case 15:
        field = &values->f148[19];
        break;
    case 1:
        field = &values->f20[4];
        break;
    }
    result = 0;
    if (field != NULL)
        result = func_L00_007102B0(index, *field);
    return result;
}
