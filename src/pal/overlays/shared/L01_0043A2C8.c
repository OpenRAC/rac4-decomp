/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_002214E0;
s32 D_002214E8;
extern u8 D_003A63A0[];
void *func_L01_0043A2C8(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 13: *size = 4; return &D_002214E0;
    case 14: *size = 28; return D_003A63A0;
    case 15: *size = 16; return &D_002214E8;
    default: return 0;
    }
}
