/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_00520F68(s32);
extern s32 func_00520FC0(s32, s32);
extern void func_00521010(s32, s32, s32, s32);
extern void func_L00_00520A68(s32);
extern s32 func_L00_00520F08(void);
s32 func_L00_00541F08(s32 *arg0) {
    s32 a = func_L00_00520F08();
    s32 b = func_L00_00520F08();
    s32 r;
    func_L00_00520A68(a);
    if (arg0[1] == 0x17) func_00521010(arg0[2], arg0[0], 1, b);
    r = func_00520FC0(b, a);
    func_00520F68(b);
    func_00520F68(a);
    return r;
}
