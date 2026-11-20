/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern void func_00403308(void *, s32, s32);
extern void func_00403440(s32);
extern s32 func_0040B410(s32);
extern void func_0040B688(void *, s32);
extern s32 func_0040DE18(void *, void *);
extern void func_0040DE68(void *);
extern s32 func_0040DF20(void *, s32, s32, s32 *);
s32 func_0040B5B8(s32 a0, s32 a1, s32 a2, s32 a3) {
    char s0[8];
    char s10[0x20];
    s32 s30;
    s32 r;
    func_00403308(s0, 0, 8);
    func_00403308(s10, 0, 0x20);
    func_0040B688(s0, a3);
    r = func_0040B410(func_0040DE18(s10, s0));
    if (r == 0) {
        s30 = 0;
        r = func_0040B410(func_0040DF20(s10, a0, a2, &s30));
        if (s30 != 0) {
            func_00403440(s30);
        }
        func_0040DE68(s10);
    }
    return r;
}
