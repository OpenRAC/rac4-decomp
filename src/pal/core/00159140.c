#include "common.h"

s32 D_0021DD3C = 0;
s32 D_0021DD78 = 0;
extern s32 func_00158A40(s32, s32, void *);
extern s32 func_00157FA8(void);
extern s32 func_00159498(s32);

/* PAL: from rac3-decomp's func_0013CA30 */
s32 func_00159140(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (D_0021DD3C == 1) return 0;
    if (D_0021DD78 != 0) {
        while (func_00157FA8() != 0);
    }
    func_00159498(0);
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    return D_0021DD3C = func_00158A40(0x2A, 0x10, buf);
}
