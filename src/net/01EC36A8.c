/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern s32 func_01EC3460(void);
extern s32 func_01EC3498(void);
extern s32 func_01EC4318(s32, s32);
s32 func_01EC36A8(s32 a0, s32 a1) {
    s32 t = func_01EC3460();
    s32 r;
    if (t != 0) {
        r = t;
    } else {
        r = func_01EC4318(a0, a1);
        func_01EC3498();
    }
    return r;
}
