/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011D5D8(const char *fmt, ...);
extern s32 D_0016F8E0[];
extern s32 D_0016F8E4[];
extern char D_001A3D50[];

/* Takes the pointer stored in D_0016F8E0, copies the value it points to into *arg0 and clears it. */
s32 func_001525A8(s32 *arg0) {
    if (D_0016F8E4[0] == -1) {
        return 0x8000000A;
    }
    if (arg0 == NULL) {
        func_0011D5D8(D_001A3D50);
        return 0x80000004;
    }
    *arg0 = *(s32 *)D_0016F8E0[0];
    *(s32 *)D_0016F8E0[0] = 0;
    return 0;
}
