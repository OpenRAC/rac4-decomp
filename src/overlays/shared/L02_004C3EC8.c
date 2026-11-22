/* cflags: @ee29 -O2 -G8 */
#include "common.h"
extern s32 D_002221B8;
extern u8 D_003A5F90[];
void *func_L02_004C3EC8(s32 arg0, s32 arg1, u32 *arg2) {
    switch (arg1) {
    case 0:
        *arg2 = 4;
        return &D_002221B8;
    case 6:
        *arg2 = 0xD0;
        return D_003A5F90;
    default:
        return 0;
    }
}
