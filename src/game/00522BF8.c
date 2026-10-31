#include "common.h"

extern s32 func_004A7DB0(s32 arg0);
extern void func_00522868(void *arg0, s32 arg1);

/* Clears the flag at 0x2EE8 and the byte at 0x2666 when the byte at 0x266D or arg1 is set; if the 0x266D byte is set, runs the object's hook and func_00522868. */
void func_00522BF8(u8 *arg0, s32 arg1) {
    s32 t = arg0[0x266D] != 0;
    if ((t != 0 || arg1 != 0) && *(s32 *)(arg0 + 0x2EE8) != 0) {
        s32 u = t == 1;
        *(s32 *)(arg0 + 0x2EE8) = 0;
        arg0[0x2666] = 0;
        if (u != 0) {
            s32 (*hook)(void *) = *(s32 (**)(void *))(*(u8 **)(arg0 + 0x14) + 0x4C);
            func_00522868(arg0, func_004A7DB0(hook(arg0)));
        }
    }
}
