/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } A8;
typedef struct { u8 b[4]; } Buf4;
typedef struct { s32 f0; char _p4[0x18]; A8 f1C; s32 f24; char _p28[4]; s32 f2C[3]; s32 f38; } Obj;
extern s32 func_01EA7830(s32, A8, s32, Buf4 *, s32, s32 *);
extern s32 func_01EAB2A0(s32 *, u32 *);
extern void func_01EAB288(s32 *);
s32 func_01EC2960(Obj *o) {
    Buf4 buf;
    u32 t;
    s32 cnt = 0;
    if (o->f38 != 0) {
        func_01EAB2A0(o->f2C, &t);
        if (t > 5000) {
            buf.b[3] = 0xD4;
            func_01EA7830(o->f0, o->f1C, o->f24, &buf, 4, &cnt);
            func_01EAB288(o->f2C);
        }
    }
    return 0;
}
