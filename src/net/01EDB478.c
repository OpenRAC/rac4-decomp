/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Checks the record at arg2 through the helper calls and, for mode 2, stores the sum of two fields into arg1.
extern s32 func_01EAA130();
extern s32 func_01EAA218(s32 op, u8 *p, u8 *data);

s32 func_01EDB478(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *temp_s3;

    temp_s3 = arg2 + 0x30;
    if (func_01EAA218(arg0, arg1, temp_s3) == 0) {
        return -0xA;
    }
    if (temp_s3[0] != 0) {
        if (func_01EAA130(arg0, arg1, arg2 + 0x34, 4) == 0) {
            return -0x15;
        }
        if (func_01EAA130(arg0, arg1, arg2 + 0x38, 4) == 0) {
            return -0x15;
        }
        if (temp_s3[0] >= 2) {
            if (func_01EAA130(arg0, arg1, arg2 + 0x3C, 4) == 0) {
                return -0x15;
            }
        }
        if (arg2[0x30] == 4) {
            if (func_01EAA130(arg0, arg1, arg2 + 0x44, 4) == 0) {
                return -0x15;
            }
            if (func_01EAA130(arg0, arg1, arg2 + 0x40, 4) == 0) {
                return -0x15;
            }
            if (func_01EAA130(arg0, arg1, arg2 + 0x48, 4) == 0) {
                return -0x15;
            }
        }
    }
    if (arg0 == 2) {
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 8) + *(s32 *)(arg2 + 0x2C);
    }
    return 0;
}
