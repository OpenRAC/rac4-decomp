/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type1;

s32 func_0011A518(void *, s32, s32);

s32 func_01EC9288(Type1 *arg0)
{
    if (arg0 == NULL) {
        return 0x17;
    }
    func_0011A518(arg0, 0, 0x14);
    arg0->f0 = 0x10;
    arg0->f4 = 0x40;
    arg0->f8 = 0x1000;
    arg0->fC = 0x10;
    arg0->f10 = 0x800;
    return 0;
}
