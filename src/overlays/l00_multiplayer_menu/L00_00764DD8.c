#include "common.h"

void func_L00_00764D88();
extern s32 D_00221748[];
s32 D_00221758 = 0;

/* returns entry arg0 of the table at D_00221758 when arg0 is below 8, else the address of D_00221748 */
s32 func_L00_00764DD8(s32 arg0) {
    s32 result;

    if (D_00221758 == 0) {
        func_L00_00764D88();
    }
    if (arg0 < 8) {
        result = *(s32 *)((arg0 * 4) + (u32)&D_00221758);
    } else {
        result = (s32)D_00221748;
    }
    return result;
}
