/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0x28];
    s32 f2C;
    char _p30[0x78];
    s32 fA8;
    s32 fAC;
    s32 fB0;
    s32 fB4;
    s32 fB8;
    s32 fBC;
};

s32 func_0011A518(void *, s32, s32);
s32 func_01E9E710(void *);

s32 func_01EA3348(Type1 *arg0) {
    if (arg0 == NULL) {
        return 0x17;
    }
    func_0011A518(arg0, 0, 0xC0);
    arg0->f2C = 8;
    arg0->fA8 = 0;
    arg0->fAC = 0;
    arg0->fB4 = 1;
    arg0->fB0 = 0;
    arg0->fB8 = 0x2000;
    arg0->fBC = 0x2000;
    func_01E9E710((u8 *)arg0 + 0x30);
    arg0->f0 = 1;
    return 0;
}
