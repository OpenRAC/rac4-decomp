#include "common.h"

extern s32 func_00157F98(void);
extern s32 func_00158A30(s32 id, s32 size, void *data);
extern s32 func_00159488(s32 arg0);

s32 D_0021DCB4 = 0;
s32 D_0021DCF0 = 0;

/* from rac3-decomp's func_0013CA30 */
s32 func_00159130(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (D_0021DCB4 == 1) return 0;
    if (D_0021DCF0 != 0) {
        while (func_00157F98() != 0) {
        }
    }
    func_00159488(0);
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    return D_0021DCB4 = func_00158A30(0x2A, 0x10, buf);
}
