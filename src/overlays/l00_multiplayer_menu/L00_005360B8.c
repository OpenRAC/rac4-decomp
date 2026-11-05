/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s64 f18;
    s32 f20;
    s32 f24;
    s32 *f28;
} Type1;
typedef union Type2 {
    s64 l;
    s32 w;
} Type2;
s32 func_L00_00535C18(Type1 *, s64 *, s32 *, s32 *, s64);
/* Runs the step callback and updates the remaining count; returns 1 on success. */
s32 func_L00_005360B8(Type1 *arg0, Type2 *arg1) {
    s32 saved = arg0->f0;
    s32 status;
    status = func_L00_00535C18(arg0, &arg0->f18, &arg0->f10, &arg0->f14, arg1->l);
    arg0->fC = status;
    if (status & 0x80) {
        arg0->f8 = 6;
        return 0;
    }
    if (arg0->f10 != 0x10) {
        arg0->f8 = 7;
        return 0;
    }
    arg1->l -= arg0->f0 - saved;
    if (arg0->f20 != 0 && arg1->l < 0) {
        arg0->f8 = 8;
        return 0;
    }
    if (arg0->fC == 0x21) {
        arg0->f18 = *arg0->f28 + (s32)arg1->l - arg0->f0;
    }
    arg0->f4 = 0;
    return 1;
}
