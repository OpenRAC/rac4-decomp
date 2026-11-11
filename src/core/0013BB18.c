/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_001AF010[][4][7];
extern s32 func_0012D420(void);
extern s32 func_0012D470(void);
extern void *func_0013B8C8(s32 arg0, s32 arg1, void *out);
extern void func_00127438(void *, void *);

/* from rac3-decomp's func_0012F4F0 */
s32 func_0013BB18(s32 port, s32 slot, s32 state)
{
    s32 r;
    u8 *pd;
    if (D_001AF010[port][slot][4] == 0) {
        return 0;
    }
    r = func_0012D420();
    pd = (u8 *)func_0013B8C8(port, slot, 0);
    pd[0x71] = state;
    func_00127438(pd, pd + 0x7F);
    if (r == 1) {
        func_0012D470();
    }
    return 1;
}
