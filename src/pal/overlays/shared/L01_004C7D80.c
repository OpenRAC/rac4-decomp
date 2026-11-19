/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221FC0;
s32 D_00221FC8;
extern u8 D_003AB160[];
void *func_L01_004C7D80(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 13: *size = 4; return &D_00221FC0;
    case 14: *size = 28; return D_003AB160;
    case 15: *size = 16; return &D_00221FC8;
    default: return 0;
    }
}
