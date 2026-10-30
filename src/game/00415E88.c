#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    s32 f20;
    char _p24[0x98];
    s32 fBC;
};

s32 func_00415E88(Type1 *arg0) {
    s16 temp_a0;
    s32 var_a1;
    u8 temp_v1;

    var_a1 = 0;
    if ((arg0 == NULL) || (temp_v1 = arg0->f20, (temp_v1 == 0xFE)) || (temp_v1 == 0xFD) || (temp_a0 = arg0->fBC, (temp_a0 == 0x268B)) || (temp_a0 == 0x1099)) {
        var_a1 = 1;
    }
    return var_a1;
}
