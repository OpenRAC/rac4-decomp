/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char b[0xA4]; } Req;
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC878;
extern s32 D_001BCA70;
extern s32 func_01ED5DD0(s32, s32, s32, void *);
s32 func_01ED6C30(Req *r, s32 b, s32 c) {
    r->b[0x14] = 0;
    r->b[0x25] = 0;
    r->b[0x6F] = 0;
    r->b[0x8F] = 0;
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    if (D_00169CD4 == 0) {
        return -0x10;
    }
    D_001BCA70 = b;
    D_001BC878 = c;
    return func_01ED5DD0(4, 0x14, 0xA4, r) != 0 ? -5 : 0;
}
