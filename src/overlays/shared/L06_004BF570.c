#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 func_L00_005F1208(u128, s32);

s32 func_L06_004BF570(u8 *arg0, u8 *arg1) {
    u8 *p;

    p = *(u8 **)(arg0 + 0xAC);
    if (*(u8 *)(p + 0xA) == 0) {
        return 0;
    }
    return func_L00_005F1208(*(u128 *)arg1, *(s32 *)p) != 0;
}
