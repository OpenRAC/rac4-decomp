/* Not matching yet: BYTES 11/200 (tools/try_func.py func_00146570 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x868];
    s32 f868;
} Type1;

extern s32 func_0012D420(void);
extern s32 func_0012D470(void);
extern s32 func_00142290(s32, s32 *);
extern void func_00146638(Type1 *, s32);
extern u8 D_00195750[];

void func_00146570(Type1 *p) {
    s32 buf[8];
    s32 r;
    s32 id;
    volatile s32 *p7;
    volatile s32 *p8;

    func_00146638(p, (s32)D_00195750);
    buf[0] = 2;
    func_00142290(p->f868, buf);
    id = p->f868;
    *(volatile s32 *)0x10002010 = 0x40000000;
    buf[0] = 3;
    func_00142290(id, buf);
    r = func_0012D420();
    p7 = (volatile s32 *)0x1000F520;
    p8 = (volatile s32 *)0x1000F590;
    *p8 = *p7 | 0x10000;
    *(volatile s32 *)0x1000B000 = 0;
    *p8 = *p7 & 0xFFFEFFFF;
    if (r != 0) {
        func_0012D470();
    }
    *(volatile s32 *)0x1000B020 = 0;
}
