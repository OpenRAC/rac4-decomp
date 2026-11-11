/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x154];
    s32 f154;
};

s32 func_01EFEED0(s32, void *);
s32 func_01EFFF40();
s32 func_01F0C090(void *, s32);
extern s32 D_0019DA98[];

void func_01F00074(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = func_01EFFF40();
    arg0->f154 = temp_v0;
    if (temp_v0 == 0) {
        func_01F0C090(D_0019DA98, 0xD1);
    }
    func_01EFEED0(arg0->f154, arg0);
}
