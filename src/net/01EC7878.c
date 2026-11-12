/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x3C];
    s32 (*f3C)();
};

extern Type1 *D_001681A0;

s32 func_01EC7878(s32 arg0) {
    s32 var_v0;

    if (D_001681A0 != NULL) {
        var_v0 = D_001681A0->f3C(arg0 & 0x7FFFFFFF, 0xFFFF, 0, 0);
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
