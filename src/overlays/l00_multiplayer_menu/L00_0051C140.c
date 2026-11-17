/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 (**f4)(s32); } Type1;
extern Type1 *D_004A03B8[];
extern s32 func_L00_004F9080(s32);

/* Dispatches through a handler table by index, returns result xor index. */
s32 func_L00_0051C140(s32 *arg0) {
    Type1 *t = D_004A03B8[0];
    s32 r;
    if (t != 0 && t->f0 > arg0[0]) {
        r = t->f4[arg0[0]](arg0[2]);
    } else {
        r = func_L00_004F9080(arg0[2]);
    }
    return r ^ arg0[0];
}
