#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
    char _p21[0x13];
    u8 f34;
};


s32 func_L01_00512A48(Type1 *arg0) {
    s32 var_a1;
    u8 temp_v1;

    temp_v1 = arg0->f20;
    var_a1 = 0;
    if ((temp_v1 >= 0xBU) || (((arg0->f34 ^ 1) & 1) && (temp_v1 == 1))) {
        var_a1 = 1;
    }
    return var_a1;
}
