/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C4B30 (src/levels/39_multiplayer_menu/L39_004C4B30.c, GPL-3.0), the same code in both games. */

typedef struct Type1 Type1;
typedef struct {
    char _p0[0x2C];
    s32 (*f2C)(Type1 *);
} V_004C4B30;
struct Type1 {
    char _p0[0x8];
    V_004C4B30 *f8;
    char _pC[0x20 - 0xC];
    s32 (*f20)(Type1 *);
};
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00500CE0(Type1 *);
s32 func_L00_00500930(Type1 *arg0) {
    s32 ret = 1;
    if (arg0->f20 == 0) {
        func_L00_004F84C8(0x14, 0xB4, 0x90, 0, 0);
        return -1;
    }
    arg0->f8->f2C(arg0);
    if ((func_L00_00500CE0(arg0) & 0x3000) || (func_L00_00500CE0(arg0) & 0x4000)) {
        ret = arg0->f20(arg0);
    }
    return ret;
}
