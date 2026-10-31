/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0012A718();
extern s32 func_0013AE70();
extern s32 D_00195000[];
extern s32 D_1AEE80[];
extern u8 D_1AEEC0[];

/* Stores arg0 in the RPC buffer, calls func_0012A718 (command 3), returns word 1 of the reply or 0 on error. */
s32 func_0013B0F8(s32 a) {
    s32 *p;
    *(s32 *)D_1AEEC0 = a;
    p = (s32 *)D_1AEEC0;
    if (func_0012A718(D_1AEE80, 3, 0, p, 0x80, p, 0x80, 0, 0) < 0) {
        func_0013AE70(D_00195000);
        return 0;
    }
    return p[1];
}
