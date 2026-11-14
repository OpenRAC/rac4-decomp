/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 f10; } X;
typedef struct { char _p0[0x4A4]; s32 f4A4; } Obj;
extern s32 D_00167F58;
extern X *D_00167EFC;
void func_01EABC10(s32 *);
s32 func_01EA0BF0(Obj *o) {
    if (o->f4A4 == 0) {
        return 0x2F;
    }
    if (D_00167F58 != 0) {
        func_01EABC10(&D_00167EFC->f10);
    }
    return D_00167EFC->f10;
}
