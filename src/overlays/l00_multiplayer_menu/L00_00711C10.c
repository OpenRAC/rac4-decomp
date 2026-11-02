/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x5C];
    s32 f60;
};

s32 func_L00_0069CE38(s32, s32, s32);

void func_L00_00711C10(Type1 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_a1;

    var_a1 = arg1;
    switch (var_a1) {
    case -1:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = 2;
        break;
    case 0:
        var_a1 = 3;
        break;
    }
    temp_a0 = arg0->f60;
    if (temp_a0 != 0) {
        func_L00_0069CE38(temp_a0, var_a1, 3);
    }
}
