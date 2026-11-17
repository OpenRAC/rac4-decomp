/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { u32 b[2]; } T8;
typedef struct { void *f0; s32 f4; s32 f8; s32 fC; } Req;
typedef struct { s32 f0; char _p4[0x54]; s32 f58; s32 f5C; char _p60[0x2C]; A8 f8C; A8 f94; s32 f9C; } Conn;
extern s32 func_01EA7408(void);
extern void func_01EA8B78(T8 *);
extern void func_01EA9550(s32 *, s32);
extern void *func_0011A518(void *, s32, u32);
extern s32 func_01EA75F8(Conn *, T8, s32, Req *);
extern s32 func_01EA7E78(s32, s32 *);
extern s32 func_01EA7D48(A8 *);
extern s32 func_01EA7D70(A8 *);
s32 func_01EC20E8(Conn *c) {
    Req req;
    T8 t;
    s32 r = func_01EA7408();
    if (r != 0) {
        return r;
    }
    func_01EA8B78(&t);
    func_01EA9550(&c->f58, 0x5AA);
    if (c->f58 == 0) {
        return 100;
    }
    func_01EA9550(&c->f5C, 0x5AA);
    if (c->f5C == 0) {
        return 100;
    }
    func_0011A518(&req, 0, sizeof(req));
    req.f4 = 0x5AA;
    req.f0 = (void *)1;
    r = func_01EA75F8(c, t, c->f9C, &req);
    if (r != 0) {
        return r;
    }
    r = func_01EA7E78(c->f0, &c->f9C);
    if (r != 0) {
        return r;
    }
    r = func_01EA7D48(&c->f94);
    if (r != 0) {
        return r;
    }
    return func_01EA7D70(&c->f8C);
}
