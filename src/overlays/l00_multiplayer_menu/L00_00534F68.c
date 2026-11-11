/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004F9158 (src/levels/39_multiplayer_menu/L39_004F8A78.c, GPL-3.0), the same code in both games. */

extern void *func_L00_004FACD8(s32);
extern void func_L00_004FAD28(void *);
extern void *func_L00_0051A740(void);
extern s32 func_L00_00519490(void *, s32);
extern void func_L00_00519578(void *, void *, s32);
extern void func_L00_005195A8(void *, s32, s32);
extern void func_L00_0051A7B8(void *);
s32 func_L00_00534F68(s32 (*fn)(s32, void **), s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *h;
    void *buf;
    s32 size;
    s32 ret;
    void *local;
    ret = 0;
    buf = 0;
    h = func_L00_0051A740();
    if (h != 0) {
        size = fn(arg2, 0);
        if (size > 0) {
            buf = func_L00_004FACD8(size);
            if (buf == 0) {
                goto close;
            }
        }
        local = buf;
        fn(arg2, &local);
        if (func_L00_00519490(h, arg1) != 0) {
            ret = 1;
            func_L00_00519578(h, buf, size);
            func_L00_005195A8(h, arg3, arg4);
        }
    }
    if (buf != 0) {
        func_L00_004FAD28(buf);
    }
close:
    if (h != 0) {
        func_L00_0051A7B8(h);
    }
    return ret;
}
