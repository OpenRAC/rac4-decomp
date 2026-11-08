#include "common.h"

s32 D_00221718 = 0;
s32 D_00221728 = 0;

/* from rac3-decomp's func_L04_003CD280 */
void *func_L13_00458838(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
    case 0:
        *arg2 = 12;
        return &D_00221718;
    case 19:
        *arg2 = 12;
        return &D_00221728;
    }
    return 0;
}
