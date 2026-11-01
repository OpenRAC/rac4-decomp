#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

void func_L01_00493B48(void *, s32);


void func_L01_00493C88(Type1 *arg0) {
    u8 temp_v1;

    temp_v1 = arg0->f20;
    if ((temp_v1 == 4) || (temp_v1 == 1)) {
        func_L01_00493B48(arg0, 2);
    }
}
