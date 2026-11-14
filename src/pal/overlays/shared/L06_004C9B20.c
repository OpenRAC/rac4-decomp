#include "common.h"

typedef struct Type2 {
    u8 pad0[0xAC];
    u8 *fAC;
} Type2;

extern s32 func_L06_004C9BC0(void *arg0);
extern s32 D_0021DFEC;

/* Compares the state value with the selected threshold. */
s32 func_L06_004C9B20(Type2 *arg0)
{
    u8 *state;
    s32 *thresholds;

    if (func_L06_004C9BC0(arg0) != 0) {
        state = arg0->fAC;
        thresholds = (s32 *)(state + 0x74);
        if (*(s32 *)(state + 0x88) >= thresholds[D_0021DFEC]) {
            return 1;
        }
    }
    return 0;
}
