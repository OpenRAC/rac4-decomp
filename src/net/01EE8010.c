/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x5B1C];
    s32 f5B1C;
} Type1;

s32 func_01F03D08(s32, Type1 *);

s32 func_01EE8010(Type1 *arg0)
{
    if (arg0->f5B1C == 0) {
        return 1;
    }
    return func_01F03D08(arg0->f5B1C, arg0);
}
