/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    u8 *f8;
    s32 fC;
    s64 f10;
} Type;

void *func_L00_004FACD8(s32);
void *func_004FAD00(void *, s32, s32);
s32 func_0011AB04(u8 *);
s32 func_0011A370(u8 *, u8 *, s32);

s32 func_L00_00536190(Type *arg0, u8 *arg1, s32 arg2) {
    s32 len = arg2;
    u8 *cur;
    u8 *old;

    if (len < 0) {
        if (arg1 == 0)
            return 0;
        len = func_0011AB04(arg1);
    }
    cur = arg0->f8;
    if (arg0->f0 >= len) {
        old = cur;
        if (cur != 0)
            goto store;
    } else {
        old = cur;
    }
    if (cur == 0)
        arg0->f8 = func_L00_004FACD8(len + 1);
    else
        arg0->f8 = func_004FAD00(cur, len + 1, 0);
    cur = arg0->f8;
    if (cur == 0) {
        arg0->f8 = old;
        return 0;
    }
store:
    arg0->f0 = len;
    if (arg1 != 0) {
        func_0011A370(cur, arg1, len);
        arg0->f8[len] = 0;
    }
    arg0->f10 = 0;
    return 1;
}
