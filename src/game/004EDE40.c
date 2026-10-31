#include "common.h"

/* Returns 1 or the halfword at +0xBC of arg0's +0x2EC record, storing that record into D_0022084C; returns 0 when D_002208D4 < D_0021DDB8. */
extern void *func_00510BE8(s32 arg0);
extern s32 D_0021DDB8;
extern s32 D_0022084C;
s32 D_002208D4 = 0;

s16 func_004EDE40(void *arg0) {
    void *temp_v0;

    if (arg0 == NULL) {
        arg0 = func_00510BE8(0);
    }
    if (D_002208D4 >= D_0021DDB8) {
        temp_v0 = *(void **)((u8 *)arg0 + 0x2EC);
        D_0022084C = (s32) temp_v0;
        if (temp_v0 != NULL) {
            return *(s16 *)((u8 *)temp_v0 + 0xBC);
        }
        return 1;
    }
    D_0022084C = 0;
    return 0;
}
