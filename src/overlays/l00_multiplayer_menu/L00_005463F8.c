/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
};
struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
};

s32 func_0011A2DC(s32, s32, s32);

s32 func_L00_005463F8(Type1 *arg0, Type2 *arg1) {
    s32 temp_a2;
    s32 var_v0;

    temp_a2 = arg0->f0;
    var_v0 = temp_a2 - arg1->f0;
    if (var_v0 == 0) {
        var_v0 = func_0011A2DC(arg0->f8, arg1->f8, temp_a2);
        if (var_v0 == 0) {
            var_v0 = arg0->f4 - arg1->f4;
        }
    }
    return var_v0;
}
