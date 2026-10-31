#include "common.h"

/* Stores arg1 at byte 0x1C of entry arg0 of D_2F32B8 (0x54 bytes each) and calls func_004A7958 and func_004C5658 when it changes. */
extern void func_004A7958(s32 arg0, s32 arg1);
extern void func_004C5658();
extern u8 D_2F32B8[];

void func_00498098(s32 arg0, s32 arg1) {
    u8 *temp_a0;

    temp_a0 = &D_2F32B8[arg0 * 0x54];
    if (temp_a0[0x1C] != arg1) {
        temp_a0[0x1C] = arg1;
        func_004A7958(arg0, arg1);
        func_004C5658(arg0, arg1);
    }
}
