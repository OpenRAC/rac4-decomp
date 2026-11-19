/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_002217C0;
s32 D_002217C8;
extern u8 D_003A6C40[];
void *func_L01_004584C0(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 14: *size = 28; return D_003A6C40;
    case 13: *size = 4; return &D_002217C0;
    case 15: *size = 16; return &D_002217C8;
    default: return 0;
    }
}
