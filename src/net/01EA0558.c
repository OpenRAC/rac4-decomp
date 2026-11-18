/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA42D8(s32);
extern s32 D_00167F2C[];
extern s32 D_00167F3C[];

// Checks a device state through two vtable calls and returns a status code.
s32 func_01EA0558(u8 *arg0, s32 arg1, s32 arg2) {
    s32 r;
    if (*(s32 *)(arg0 + 0x468) == 2) {
        s32 (**vt)(s32) = *(s32 (***)(s32))D_00167F3C;
        if (vt[0x28 / 4](*(s32 *)(arg0 + 0x474)) != 0) return 0x25;
    } else {
        s32 *p = D_00167F2C;
        s32 (**vt1)(s32) = *(s32 (***)(s32))p;
        s32 (**vt)(s32, s32);
        r = func_01EA42D8(vt1[0x48 / 4](*(s32 *)(arg0 + 0x470)));
        if (r != 0) return r;
        vt = *(s32 (***)(s32, s32))p;
        r = func_01EA42D8(vt[0x4C / 4](*(s32 *)(arg0 + 0x470), arg2));
        if (r != 0) return r;
    }
    return 0;
}
