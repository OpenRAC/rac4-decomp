/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x14];
    s32 f14;
};

s32 func_01EA70F8(Type1 *, s32, s32);

s32 func_01EA70B0(Type1 *arg0, s32 arg1) {
    if (arg0 == NULL) {
        return 2;
    }
    if (arg1 != 0 && arg0->f14 == 0) {
        return 0xC9;
    }
    return func_01EA70F8(arg0, arg1, arg0->f14);
}
