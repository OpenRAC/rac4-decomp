/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221C88;
s32 D_00221C90[2];
extern u8 D_003AA3C8[];
void *func_L01_00493CC0(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 14: *size = 28; return D_003AA3C8;
    case 13: *size = 4; return &D_00221C88;
    case 15: *size = 16; return D_00221C90;
    default: return 0;
    }
}
