#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xBE];
    u8 fBE;
};

s32 func_00591BD8(void *, s32, s32);


void func_L01_00492CC8(Type1 *arg0) {
    arg0->fBE = (u8) (arg0->fBE & 0xFB);
    func_00591BD8(arg0, 2, -1);
}
