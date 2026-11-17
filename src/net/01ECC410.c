/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 w[6]; } Ring;
typedef struct { u8 f0; char _p1[3]; u8 f4; char _p5[0x27]; Ring q; } Ent;
extern Ent *func_01EC9A28(u32);
extern s32 func_01EA7248(Ring *, s32 *);
s32 func_01ECC410(s32 *out, u32 id) {
    s32 v = 0;
    Ent *e;
    s32 r;
    if (out == 0) {
        return 0x17;
    }
    *out = 0;
    e = func_01EC9A28(id);
    if (e == 0) {
        return 0x17;
    }
    if (e->f0 != 2) {
        return 9;
    }
    if (e->f4 != 0) {
        return 9;
    }
    if (&e->q == 0) {
        return 9;
    }
    if (func_01EA7248(&e->q, &v) == 0) {
        *out = v;
        return 0;
    }
    return 9;
}
