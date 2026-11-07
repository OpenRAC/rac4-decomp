/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0x4];
    s32 f8;
};

s32 func_0011A518(void *, s32, s32);
s32 func_01EB6250();

void func_01EB61E0(Type1 *arg0) {
    s32 *temp_v1;

    if ((arg0 != NULL) && (arg0->f8 != NULL) && (arg0->f0 != 0)) {
        func_01EB6250();
        temp_v1 = arg0->f8;
        *temp_v1 -= 1;
        func_0011A518(arg0, 0, 0x10);
    }
}
