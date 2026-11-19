/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_002218E0;
s32 D_002218E8;
extern u8 D_003A9750[];
void *func_L01_00468850(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 14: *size = 28; return D_003A9750;
    case 13: *size = 4; return &D_002218E0;
    case 15: *size = 16; return &D_002218E8;
    default: return 0;
    }
}
