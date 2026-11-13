/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 *D_00167EFC[];
extern void func_01EA8B78(void *a0);
extern s32 func_01EA55E8(void);
extern void func_01EA1368(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

/* Reset the network object's field and start a transfer with the given args. */
void func_01EA2018(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (a3 != 0) {
        func_01EA8B78((u8 *)D_00167EFC[0] + 0x18);
        *(s32 *)((u8 *)D_00167EFC[0] + 0x20) = 0;
        func_01EA1368(func_01EA55E8(), a0, a1, a2, a3);
    }
}
