/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x1C];
    s32 f1C;
} Type1;

s32 func_01EA8928(void);

s32 func_01EA7E78(Type1 *arg0, s32 *arg1)
{
    *arg1 = 0;
    if (func_01EA8928() == 0) {
        return 2;
    }
    *arg1 = arg0->f1C;
    return 0;
}
