/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x198];
    void *f198;
    u16 f19C;
};

void func_0011A518(void *, s32, s32);
s32 func_01EBBBE8(Type1 *, s8);

s32 func_01EBBDC0(Type1 *arg0, u32 arg1) {
    u32 i;
    s32 r;

    func_0011A518(arg0->f198, -1, arg0->f19C * 3);
    for (i = 0; i < arg1; i++) {
        r = func_01EBBBE8(arg0, i);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
