/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0x4];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
};

void func_0011A518(void *, s32, s32);

s32 func_01E9E710(Type1 *arg0) {
    if (arg0 == NULL) {
        return 0x17;
    }
    func_0011A518(arg0, 0, 0x70);
    arg0->f8 = 1;
    arg0->fC = 1;
    arg0->f10 = 0x9C4;
    arg0->f1C = 0;
    arg0->f14 = 0x2000;
    arg0->f20 = 1;
    arg0->f24 = 0x10;
    arg0->f28 = 0x1F40;
    arg0->f2C = 1;
    arg0->f18 = 0x2000;
    arg0->f30 = 0x10;
    arg0->f34 = 0x1F40;
    arg0->f0 = 1;
    return 0;
}
