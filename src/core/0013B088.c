/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_001AEE80[0x28 / sizeof(s32)];
extern s32 func_0012A718();
extern s32 func_0013AE70();
extern u8 D_001AEEC0[];
extern u8 D_00194FE0[];

/* Stores a in D_001AEEC0, calls func_0012A718 (mode 2); returns word 1 on success, else reports and returns 0. */
s32 func_0013B088(void *a) {
    s32 *p;
    *(void **)D_001AEEC0 = a;
    p = (s32 *)D_001AEEC0;
    if (func_0012A718(D_001AEE80, 2, 0, p, 0x80, p, 0x80, 0, 0) < 0) {
        func_0013AE70(D_00194FE0);
        return 0;
    }
    return p[1];
}
