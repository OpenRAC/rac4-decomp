/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct { s32 x[4]; } Type1;
extern void func_01F0C090(void *, s32);
extern void func_01F07D98(Type1 *);
extern void func_01F07DC8(Type1 *, s32);
extern void func_01EE7098(s32, s32, s32, s32, Type1 *, s32);
extern char D_0019B460[];
void func_01EE6EE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Type1 tmp;
    if (arg3 == 0) {
        func_01F0C090(D_0019B460, 0x3AB);
    }
    func_01F07D98(&tmp);
    func_01EE7098(arg3, arg0, arg1, arg2, &tmp, arg4);
    func_01F07DC8(&tmp, 2);
}
