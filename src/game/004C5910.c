#include "common.h"

typedef struct { char _p[0xC]; u8 fC; char _pd[3]; s32 f10; char _p14[0xB1C]; } St;
extern St D_0030B9D8[];
extern s32 D_002218C8;
s32 func_00505B20(void);
void func_0049C4B0(s32, s32, s32, s32);
void func_004C8118(void);
void func_00497EB8(s32, s32);
void func_0049B0D8(s32);
void func_004C5910(void) {
    s32 i = func_00505B20();
    St *s;
    D_0030B9D8[i].f10 = 0;
    s = &D_0030B9D8[i];
    func_0049C4B0(i, 0, D_002218C8, 0);
    func_004C8118();
    if (s->fC != 0) {
        func_00497EB8(i, 0);
    } else {
        func_0049B0D8(i);
    }
}
