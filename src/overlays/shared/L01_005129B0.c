/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

s32 func_L01_00591C58(s32, s32);

void func_L01_005129B0(Type1 *arg0) {
    u8 temp_v1;

    temp_v1 = arg0->f20;
    if ((temp_v1 == 1) || (temp_v1 == 4) || (temp_v1 == 8)) {
        func_L01_00591C58(arg0, 1);
    }
}
