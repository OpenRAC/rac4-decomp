/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011EAA0(char *file, s32 line, char *expr);
extern void func_01EAE190(void *arg0, void *arg1, s32 arg2);
extern void func_01EE0E50(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_01EE10F0(void *arg0);
extern char D_00199DF8[];
extern char D_00199E60[];

/* Initialises the header at arg1, then sets up the link at arg0 for its current state, or reports a failure. */
s32 func_01EDF0D0(u8 *arg0, u8 *arg1) {
    s32 temp_v1;

    arg1[0] = 0x14;
    arg1[1] = 3;
    arg1[2] = 0;
    arg1[3] = 0;
    arg1[4] = 1;
    arg1[5] = 1;
    if (*(s32 *)(arg0 + 8) == 0 && *(s32 *)(arg0 + 0xC) == 0) {
        func_01EE0E50(arg0 + 0xE0, arg0 + 0xB0, arg0 + 0x70, arg0 + 0x90);
        func_01EE10F0(arg0);
    }
    temp_v1 = *(s32 *)(arg0 + 4);
    *(s32 *)(arg0 + 8) = temp_v1;
    if ((u32)(temp_v1 - 3) < 2) {
        func_01EAE190(arg0 + 0x210, arg0 + 0x130, 0x10);
    } else {
        func_0011EAA0(D_00199DF8, 0x1D0, D_00199E60);
    }
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    return 6;
}
