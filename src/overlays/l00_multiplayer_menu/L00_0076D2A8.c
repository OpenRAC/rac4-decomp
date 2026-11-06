#include "common.h"

typedef struct S_arg0 S_arg0;
struct S_arg0 {
    s32 f0;
    s32 f4;
    s32 f8;
    u32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    char _p20[0xAC];
    s32 fCC;
    s32 fD0;
    s32 fD4;
};

extern s32 func_0011A518(void *, s32, s32);

void func_L00_0076D2A8(S_arg0 *arg0, s32 arg1) {
    arg0->f0 = 0;
    arg0->f8 = 0;
    arg0->f10 = 0;
    arg0->f14 = 0;
    arg0->f18 = 0;
    arg0->f1C = 0;
    arg0->fC = 0xFFFFFFFF;
    arg0->f4 = (s32) ((arg0->f4 & ~0xFFF) | (arg1 & 0xFFF));
    func_0011A518((char *)arg0 + 0x20, 0, 0xAC);
    arg0->fCC = 0;
    arg0->fD0 = 0;
    arg0->fD4 = 0;
}
