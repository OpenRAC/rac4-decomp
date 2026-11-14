/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; } Obj;
extern void func_01EC1DF8(Obj *, s32, s32 *);
extern s32 func_01EC1DB8(s32, Obj *, s32);
extern s32 func_01EC1D40(s32, Obj *);
s32 func_01EC1310(s32 a, s32 b, Obj *o) {
    s32 st = 0;
    if (o == 0) {
        return 0xD2F3;
    }
    func_01EC1DF8(o, b, &st);
    if (st == 0) {
        if (o->f0 == 13) {
            o->f0 = 4;
            return func_01EC1DB8(a, o, b);
        }
        if (o->f0 == 5 || o->f0 == 6) {
            return func_01EC1DB8(a, o, b);
        }
        o->f0 = 2;
        return func_01EC1D40(a, o);
    }
    return func_01EC1DB8(a, o, b);
}
