/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char b[0xE8]; } Req;
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC874;
extern s32 D_001BCA6C;
extern s32 func_01ED5DD0(s32, s32, s32, void *);
s32 func_01ED6B28(Req *r, s32 b, s32 c) {
    r->b[0x14] = 0;
    r->b[0x25] = 0;
    r->b[0x77] = 0;
    r->b[0x97] = 0;
    r->b[0xB7] = 0;
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    if (D_00169CD4 == 0) {
        return -0x10;
    }
    D_001BCA6C = b;
    D_001BC874 = c;
    return func_01ED5DD0(4, 0x2F, 0xE8, r) != 0 ? -5 : 0;
}
