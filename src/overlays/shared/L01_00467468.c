#include "common.h"
extern u8 D_003A9750[];
s32 D_002218B0 = 0;
s32 D_002218B8 = 0;
s32 *func_L01_00467468(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 14:
        *a2 = 28;
        return (s32 *)D_003A9750;
    case 13:
        *a2 = 4;
        return &D_002218B0;
    case 15:
        *a2 = 16;
        return &D_002218B8;
    }
    return 0;
}
