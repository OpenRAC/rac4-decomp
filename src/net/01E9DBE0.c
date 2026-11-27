/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { char _p0[0x10]; s32 f10; char _p14[0x28]; struct Node *f3C; } Node;
typedef struct {
    char _p0[4];
    s32 f4;
    char _p8[4];
    s32 fC;
    char _p10[4];
    u8 *f14;
    u8 *f18;
    s32 f1C;
    s32 f20;
} Obj;

extern Node *D_00167EEC[];
extern void func_0011A370(u8 *dst, u8 *src, s32 n);

s32 func_01E9DBE0(Obj *o) {
    Node *n = D_00167EEC[0];
    while (n != 0) {
        if (n->f10 == o->f4) {
            s32 avail = o->fC;
            s32 want = o->f1C - 0x24;
            u8 *buf = __builtin_alloca(((u32)(avail + 0xF) >> 4) << 4);
            func_0011A370(buf, o->f14 + 0x24, want);
            buf += want;
            if (o->f18 != 0 && avail - want >= o->f20) {
                func_0011A370(buf, o->f18, o->f20);
            }
            n = 0;
        } else {
            n = n->f3C;
        }
    }
    return 0;
}
