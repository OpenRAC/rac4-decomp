/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221CB8;
s32 D_00221CC0;
extern u8 D_003AA3C8[];
void *func_L01_004954B8(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 14: *size = 28; return D_003AA3C8;
    case 13: *size = 4; return &D_00221CB8;
    case 15: *size = 16; return &D_00221CC0;
    default: return 0;
    }
}
