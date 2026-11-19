/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221B78;
s32 D_00221B80;
extern u8 D_003A9E28[];
void *func_L01_00487300(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 13: *size = 4; return &D_00221B78;
    case 14: *size = 28; return D_003A9E28;
    case 15: *size = 16; return &D_00221B80;
    default: return 0;
    }
}
