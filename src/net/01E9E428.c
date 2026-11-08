/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB4];
    s32 fB4;
};

s32 func_01EA33C0(void *, s32);
s32 func_01EA42D8(s32);
s32 func_01EA57B8();
s32 func_01EA57F8();
extern s32 D_00167F58[];

s32 func_01E9E428(Type1 *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01EA33C0(arg0, arg1);
        if ((arg0->fB4 != 0) && (temp_s0 != 0)) {
            D_00167F58[0] = 0;
        }
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
