/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A2DC();
extern void func_004FAD28(s32);
extern void *func_L00_004FACD8();
extern s32 func_L00_0051FDC0();

/* decodes into a temporary buffer, copies the tail out and reports success */
s32 func_L00_0051FCB8(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    u32 len;
    s32 ok;
    s32 ret;
    void *p;

    ret = 1;
    p = func_L00_004FACD8(arg4);
    ok = 0;
    if (p != 0) {
        ret = func_L00_0051FDC0(arg0, 4, p, &len, arg4, arg2, arg4, arg7);
        if (ret == 0 && len >= arg6) {
            ok = func_0011A2DC(arg5, (s32)p + (len - arg6), arg6) == 0;
        }
    }
    if (arg3 != 0) {
        *arg3 = ok;
    }
    if (p != 0) {
        func_004FAD28((s32)p);
    }
    return ret;
}
