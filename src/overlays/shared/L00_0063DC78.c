#include "common.h"

typedef struct {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x194 - 0x14];
    Type2 f194[8];
    s32 f1F4;
} Type1;

extern Type1 D_0030F6F0[];

void func_L00_0063DC78(s32 arg0) {
    Type1 *rec = D_0030F6F0 + arg0;
    rec->f1F4 = 0;
}
