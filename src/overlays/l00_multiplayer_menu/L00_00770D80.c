#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    u8 f0;
    s32 f4;
    u8 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 f1C;
    char _p1D[0x7];
    u8 f24;
};

Type1 *func_L00_00770D80(Type1 *arg0) {
    arg0->f0 = 0;
    arg0->f4 = -1;
    arg0->f8 = 0;
    arg0->fC = -1;
    arg0->f10 = -1;
    arg0->f14 = 0;
    arg0->f18 = 0;
    arg0->f1C = 0;
    arg0->f24 = 0;
    return arg0;
}
