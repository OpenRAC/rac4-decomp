/* cflags: @ee29 -O2 -G8 */
#include "common.h"
s32 D_00221BF0;
s32 D_00221BF8[2];
s32 D_00221C08[2];
void *func_L01_00490458(void *arg0, s32 kind, s32 *size) {
    switch (kind) {
    case 0: *size = 4; return &D_00221BF0;
    case 19: *size = 12; return D_00221BF8;
    case 17: *size = 12; return D_00221C08;
    default: return 0;
    }
}
