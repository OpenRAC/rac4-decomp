#include "common.h"

s32 func_L00_006A0428(s32 handle, s32 a, s32 b);

s32 func_L00_00715FC0(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;

    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x5C)));
    if (temp_a0 != 0) {
        func_L00_006A0428(temp_a0, arg1, arg2);
    }
    temp_a0_2 = (*(s32 *)((s8 *)(arg0) + (0x64)));
    if (temp_a0_2 != -1) {
        func_L00_006A0428(temp_a0_2, arg1, arg2);
    }
    temp_a0_3 = (*(s32 *)((s8 *)(arg0) + (0x68)));
    if (temp_a0_3 != -1) {
        func_L00_006A0428(temp_a0_3, arg1, arg2);
    }
    return 1;
}
