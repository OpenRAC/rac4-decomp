/* Not matching yet: BYTES 10/104 (tools/try_func.py func_01ED5D68 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_01ED94A8(void);
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s16 D_00169CD8;
extern s8 D_00169CE0[];

s32 func_01ED5D68(void) {
    func_0011A518(D_00169CE0, 0, 0x11);
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    func_01ED94A8();
    D_00169CD0 = 0;
    D_00169CD8 = 0;
    D_00169CD4 = 0;
    return 0;
}
