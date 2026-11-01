#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x20];
    u8 f20;
};

s32 func_L01_00493B48(void *, s32);


void func_L01_00493C58(Type1 *arg0) {
    if ((u32) (arg0->f20 - 2) < 2U) {
        func_L01_00493B48(arg0, 4);
    }
}
