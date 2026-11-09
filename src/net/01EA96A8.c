/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
};

s32 func_0011A518(s32, s32, s32);
s32 func_01EA9618(Type1 *, s32, u16);
s32 func_01EA96A8(Type1 *arg0, s32 arg1, u16 arg2) {
    s32 r;
    if (arg0 != NULL) {
        r = 0x64;
        if (arg1 != 0) {
            arg0->f0 = 0;
            arg0->f4 = 0;
            r = func_01EA9618(arg0, arg1, arg2);
            if (r == 0) {
                if (arg0->f4 != 0) {
                    func_0011A518(arg0->f4, 0, arg1);
                    return 0;
                }
                goto fail;
            }
        }
        return r;
    }
fail:
    return 0x64;
}
