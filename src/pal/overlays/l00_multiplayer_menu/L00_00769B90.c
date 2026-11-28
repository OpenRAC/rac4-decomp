#include "common.h"

extern const char *D_L00_004EEB50[];
extern const char D_L00_004C0DC8[];
extern void func_L00_00769B30(void);

const char *func_L00_00769B90(s32 index)
{
    const char *result;

    if (D_L00_004EEB50[0] == NULL)
        func_L00_00769B30();

    switch (index) {
    case 0:
        result = D_L00_004EEB50[0];
        break;
    case 3:
        result = D_L00_004EEB50[1];
        break;
    case 4:
        result = D_L00_004EEB50[2];
        break;
    case 1:
        result = D_L00_004EEB50[3];
        break;
    case 2:
        result = D_L00_004EEB50[4];
        break;
    default:
        result = D_L00_004C0DC8;
        break;
    }
    return result;
}
