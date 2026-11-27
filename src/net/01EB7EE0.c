/* cflags: @ee296 -O2 -G8 */
#include "common.h"

typedef struct { char _p0[0x184]; void *slots; char _p188[0x14]; u16 f19C; char _p19E[4]; u16 f1A2; u16 f1A4; } Conn;
extern s32 func_01EBAA38(Conn *);
extern s32 func_01EBAD88(Conn *);
extern s32 func_01EBBA48(Conn *);
extern s32 func_01EBD2A8(Conn *);
extern void func_01EABE78(s32 *);
extern void func_01EBCB40(Conn *);

s32 func_01EB7EE0(Conn *c) {
    s32 res;
    s32 sp0;
    u16 v;

    res = 2;
    if (c != 0) {
        res = func_01EBAA38(c);
        if (res == 0) {
            res = func_01EBAD88(c);
            if (res == 0) {
                res = func_01EBBA48(c);
                if (res == 0) {
                    res = func_01EBD2A8(c);
                    if (res == 0) {
                        v = c->f1A2;
                        if (v != 0xFFFE && v != c->f1A4) {
                            sp0 = 0;
                            func_01EABE78(&sp0);
                            if (sp0 != 0) {
                                func_01EBCB40(c);
                            }
                        }
                        res = 0;
                    }
                }
            }
        }
    }
    return res;
}
