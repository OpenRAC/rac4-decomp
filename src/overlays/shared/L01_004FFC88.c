/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern u8 D_003ABFA0[];
extern u8 D_003ABFC0[];
void *func_L01_004FFC88(s32 arg0, s32 arg1, u32 *arg2) {
    switch (arg1) {
    case 14: *arg2 = 0x1C; return D_003ABFA0;
    case 8: *arg2 = 0x24; return D_003ABFC0;
    }
    return 0;
}
