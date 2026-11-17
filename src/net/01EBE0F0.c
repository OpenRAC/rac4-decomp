/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 f10; } Sess;
extern s32 func_01EC27F8(s32);
extern s32 func_01EBE188(Sess *, s32, s32);
s32 func_01EBE0F0(Sess *c, s32 a, s32 b) {
    if (c == 0) {
        return 0xD2F2;
    }
    if (c->f10 != 0) {
        if (func_01EC27F8(c->f10) == 0) {
            return 0;
        }
        return func_01EBE188(c, a, b);
    }
    return func_01EBE188(c, a, b);
}
