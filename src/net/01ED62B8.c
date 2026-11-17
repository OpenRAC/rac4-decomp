/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char b[0x18]; s32 f18; } Req;
typedef struct { Req r; s32 f1C; s32 f20; s32 f24; } Msg;
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC83C;
extern s32 D_001BCA34;
extern s32 func_01ED5DD0(s32, s32, s32, void *);
s32 func_01ED62B8(Req *r, s32 b, s32 c) {
    Msg m;
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    if (D_00169CD4 == 0) {
        return -0x10;
    }
    r->b[0x14] = 0;
    D_001BCA34 = b;
    D_001BC83C = c;
    m.r = *r;
    m.f1C = 2;
    m.f20 = 10;
    m.f24 = 7;
    return func_01ED5DD0(4, 0x27, 0x28, &m) != 0 ? -5 : 0;
}
