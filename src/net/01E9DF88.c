/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x24]; s32 f24; char _p28[4]; } Ctx_2c;
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();
extern s32 func_01EA4150(void);
extern s32 func_01EA9DE0(void *);
extern void func_01E9FF08(void);
extern u32 D_00167F04;
extern Ctx_2c *D_00167EFC;
extern s32 D_00167F00;
s32 func_01E9DF88(void) {
    s32 r;
    s32 t;
    if (D_00167F04 == 0) {
        return 0x11;
    }
    if (D_00167F04 >= 2) {
        D_00167F04--;
        return 0;
    }
    r = func_01EA42D8(func_01EA57B8());
    if (r != 0) {
        return r;
    }
    t = func_01EA4150();
    r = func_01EA42D8(func_01EA57F8());
    if (r != 0) {
        return r;
    }
    if (t == 0) {
        r = func_01EA42D8(func_01EA9DE0(&D_00167EFC->_p28));
        if (r != 0) {
            return r;
        }
        D_00167EFC->f24 = 0;
        D_00167F00 = 0;
        D_00167F04 = 0;
    }
    func_01E9FF08();
    return t;
}
