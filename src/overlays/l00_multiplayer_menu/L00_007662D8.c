#include "common.h"

typedef struct {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad15[7];
    u8 f1C;
} Type1;

Type1 *func_L00_007662D8(Type1 *arg0) {
    arg0->f0 = 0;
    arg0->f4 = -1;
    arg0->f8 = 0;
    arg0->fC = -1;
    arg0->f10 = -1;
    arg0->f14 = 0;
    arg0->f1C = 0;
    return arg0;
}
