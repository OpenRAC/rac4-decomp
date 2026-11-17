/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } Item_14;
typedef struct { s32 f0; } Ctx_4;
extern s32 func_01EBE618(s32, s32, u16, s32);
s32 func_01EBAE58(Ctx_4 *c, Item_14 *it, u16 key, s32 d) {
    s32 r = 0xD2F3;
    if (it->f4 != 0 && it->fC != 0) {
        r = func_01EBE618(c->f0, it->f4, key, d);
        if (r != 0) {
            return r;
        }
    } else if (it->f8 != 0 && it->f10 != 0) {
        r = func_01EBE618(c->f0, it->f8, key, d);
        if (r != 0) {
            return r;
        }
    }
    return r;
}
