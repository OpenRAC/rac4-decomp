/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221C48;
s32 D_00221C50;
extern u8 D_003AA330[];
void *func_L01_00492110(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 13: *size = 4; return &D_00221C48;
    case 14: *size = 28; return D_003AA330;
    case 15: *size = 16; return &D_00221C50;
    default: return 0;
    }
}
