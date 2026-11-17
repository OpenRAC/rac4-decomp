/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA2958(void *arg0, void *arg1, void *arg2);
extern s32 func_01EA2E98(void *arg0, void *arg1, void *arg2);
extern s32 func_01EABC80(void);
extern s32 D_00167F58[];

/* Checks the state at arg0, dispatches on the word at arg0 + 8 and stores the status at arg1 + 4; returns it. */
s32 func_01EA2828(u8 *arg0, u8 *arg1) {
    u8 *temp_a1;
    s32 v;

    if (arg1 == NULL) {
        return 0x17;
    }
    if (*(s32 *)(arg0 + 0xA4) == 0) {
        *(s32 *)(arg1 + 4) = 0x17;
        return 0x17;
    }
    *(s32 *)(arg1 + 4) = 3;
    *(s32 *)arg1 = 1;
    if (arg0 == NULL) {
        *(s32 *)(arg1 + 4) = 0x17;
        return 0x17;
    }
    if (*(s32 *)arg0 == 0) {
        *(s32 *)(arg1 + 4) = 0x26;
        return 0x26;
    }
    if (*(s32 *)(arg0 + 0x158) != 0) {
        if (D_00167F58[0] != 0) {
            *(s32 *)(arg1 + 4) = 0x2F;
            return 0x2F;
        }
        func_01EABC80();
        D_00167F58[0] = 1;
    }
    temp_a1 = arg0 + 8;
    v = *(s32 *)temp_a1;
    if (v == 1 || v == 3 || v == 4) {
        *(s32 *)(arg1 + 4) = func_01EA2958(arg0, temp_a1, arg1);
    } else if (v == 2) {
        *(s32 *)(arg1 + 4) = func_01EA2E98(arg0, temp_a1, arg1);
    } else {
        *(s32 *)(arg1 + 4) = 0x17;
    }
    return *(s32 *)(arg1 + 4);
}
