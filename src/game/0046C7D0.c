#include "common.h"

typedef struct Type1 {
    u8 pad0[8];
    struct Type1 *f8;
} Type1;

typedef struct {
    u8 pad0[0x55];
    u8 f55;
    u8 pad1[6];
    Type1 *f5C;
} Type2;

extern void func_00453608(Type1 *, s32, s32);

void func_0046C7D0(Type2 *arg0, Type1 *arg1)
{
    Type1 *previous;

    if (arg1 == 0) {
        return;
    }
    if (arg0->f5C == arg1) {
        arg0->f5C = arg1->f8;
    } else {
        if (arg0->f5C == 0) {
            goto empty;
        }
        previous = arg0->f5C;
        while (previous->f8 != 0 && previous->f8 != arg1) {
            previous = previous->f8;
        }
        if (previous->f8 == arg1) {
            previous->f8 = arg1->f8;
        }
    }
    if (arg0->f5C != 0) {
        goto call;
    }
empty:
    arg0->f55 &= 0x7F;
call:
    func_00453608(arg1, 0, 0x40);
}
