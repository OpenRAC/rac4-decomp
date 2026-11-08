/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    u8 pad4[0x18];
    s32 f1C;
} Type1;

s32 func_0011A518(void *, s32, s32);

s32 func_01E9E3E0(Type1 *arg0)
{
    if (arg0 == NULL) {
        return 0x17;
    }
    func_0011A518(arg0, 0, 0x48);
    arg0->f1C = 2;
    arg0->f0 = 1;
    return 0;
}
