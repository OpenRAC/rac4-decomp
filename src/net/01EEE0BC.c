/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xA4];
    s32 fA4;
    s32 fA8;
    s32 fAC;
    char _pB0[0x3018];
    s32 f30C8;
    s32 f30CC;
    char _p30D0[0x4];
    s32 f30D4;
    s32 f30D8;
    char _p30DC[0x5C];
    s32 f3138;
    s32 f313C;
};

void func_0011A518(void *, s32, s32);
void func_01EEFE08();

void func_01EEE0BC(Type1 *arg0) {
    arg0->f30CC = 1;
    arg0->fA8 = 0;
    arg0->fA4 = 0;
    arg0->fAC = 0;
    arg0->f30D4 = 0;
    arg0->f30D8 = 0;
    arg0->f30C8 = 0;
    func_01EEFE08();
    arg0->f30CC = 1;
    func_0011A518((void *)((u8 *)arg0 + 0x2C), 0, 0x4C);
    arg0->f3138 = 0xFF;
    arg0->f313C = 0xFFFF;
}
