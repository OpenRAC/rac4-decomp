#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
};

s32 func_01EA95C0();

s32 func_01EA9718(Type1 *arg0) {
    s32 var_v0;

    var_v0 = 0x64;
    if (arg0 != NULL) {
        if (arg0->f0 != 0) {
            var_v0 = func_01EA95C0();
            if (var_v0 == 0) {
                arg0->f0 = 0;
                goto block_4;
            }
        } else {
block_4:
            arg0->f4 = 0;
            var_v0 = 0;
        }
    }
    return var_v0;
}
