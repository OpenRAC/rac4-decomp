/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 h; s32 cur; void (*cb)(s32); } S;
void func_00403308(s32, s32, s32);
s32 func_004033D0(s32, s32);
s32 func_00403280(S *s, s32 v) {
    s32 h;
    if (s->cb != 0) {
        s->cb(s->h);
    }
    if (s->cur == v) {
        return 0;
    }
    func_00403308(s->h, 0, s->cur);
    h = func_004033D0(s->h, v);
    s->h = h;
    if (h == 0) {
        s->cur = 0;
        return 0x206;
    }
    s->cur = v;
    return 0;
}
