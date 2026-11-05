/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    char _p0[0x4];
    s32 f4;
} Type1;

typedef struct Type2 {
    char _p0[0x10];
    u32 f10;
} Type2;

extern s32 func_0011A2DC();
extern void func_004FAD28(void *);
extern s32 func_0051EC50(void *, void *, u32 *, u32, s32, s32, s32);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);
extern void *func_L00_00526A08(Type1 *);

// Read a record into a fresh buffer and compare its last n bytes with dst.
s32 func_L00_00526410(s32 arg0, void *dst, u32 n, s32 arg3, s32 arg4, Type1 *arg5) {
    s32 sp0;
    Type2 *sp4;
    u32 len;
    void *h;
    void *buf;
    s32 ret;

    ret = 0;
    buf = 0;
    sp4 = 0;
    sp0 = 0;
    h = func_L00_00526A08(arg5);
    if (h != 0 && func_L00_005208E8(arg5->f4, 0x10, 0x10, (s32)&sp0, &sp4, 0) == 0 && sp4 != 0) {
        len = sp4->f10;
        buf = func_L00_004FACD8(len);
        if (buf != 0 && func_0051EC50(h, buf, &len, len, arg3, arg4, 0) == 0) {
            if (n != 0 && n < len && func_0011A2DC(dst, (u8 *)buf + (len - n), n) == 0) {
                ret = 1;
            } else {
                ret = 0;
            }
        }
    }
    if (buf != 0) {
        func_004FAD28(buf);
    }
    return ret;
}
