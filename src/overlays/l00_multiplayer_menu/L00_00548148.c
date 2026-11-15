/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00552008(void *);
extern s32 func_L00_00552038(u8 *a0, s32 a1);
extern s32 func_L00_00552048(void *, s32);
extern void func_L00_005522F8(void *);
extern void func_L00_00552380(void *arg0);
extern s32 func_L00_005523E0();
extern s32 func_L00_00552C88(void *, s32);
extern void func_L00_00551E18(void);

/* Runs a lookup with a caller-supplied or temporary stack context, trying each handler in turn. */
s32 func_L00_00548148(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 buf[0xF0];
    void *p;
    s32 r;

    if (arg0 == 0) {
        func_L00_00552008(buf);
        func_L00_00552038(buf, (s32)func_L00_00551E18);
        p = buf;
    } else {
        func_L00_00552380(arg0);
        p = arg0;
    }
    if (arg1 == 0 || (r = func_L00_00552048(p, arg1)) == 0) {
        r = func_L00_005523E0(p, arg3, arg4, arg5);
        if (r == 0) {
            r = func_L00_00552C88(p, arg2);
        }
    }
    if (arg0 == 0) {
        func_L00_005522F8(buf);
    }
    return r;
}
