/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221FB0;
s32 D_00221FB8;
extern u8 D_003AADD8[];
void *func_L01_004BC800(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 13: *size = 4; return &D_00221FB0;
    case 14: *size = 28; return D_003AADD8;
    case 15: *size = 16; return &D_00221FB8;
    default: return 0;
    }
}
