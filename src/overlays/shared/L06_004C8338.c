#include "common.h"

extern s32 D_0021DF64;
extern s32 func_L06_004C8388(void *arg0);

/* checks a state value against a table entry */
s32 func_L06_004C8338(void *arg0) {
    u8 *p;
    if (func_L06_004C8388(arg0) != 0) {
        p = *(u8 **)((u8 *)arg0 + 0xAC);
        if (*(s32 *)(p + 0x88) < *(s32 *)(p + (D_0021DF64 << 2) + 0x74)) {
            return 1;
        }
    }
    return 0;
}
