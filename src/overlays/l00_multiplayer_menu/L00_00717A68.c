#include "common.h"
/* Ported from rac3-decomp's func_L39_00685AE0 (src/levels/39_multiplayer_menu/L39_00684488.c, GPL-3.0), the same code in both games. */

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);
void func_L00_00717A68(u8 *obj, u8 *str) {
    u8 *p;
    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x58) + 0xF8))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
}
