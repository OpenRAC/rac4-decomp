/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221EC0;
s32 D_00221EC8;
extern u8 D_003AAD78[];
void *func_L01_004B2F38(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 14: *size = 28; return D_003AAD78;
    case 13: *size = 4; return &D_00221EC0;
    case 15: *size = 16; return &D_00221EC8;
    default: return 0;
    }
}
