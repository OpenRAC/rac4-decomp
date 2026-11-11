#include "common.h"

s32 D_00221F68 = 0;
s32 D_00221F60 = 0;

/* from rac3-decomp's func_L04_00313D88 */
void *func_L05_004C1F00(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {
    case 11:
        *arg2 = 16;
        return &D_00221F68;
    case 20:
        *arg2 = 8;
        return &D_00221F60;
    }
    return 0;
}
