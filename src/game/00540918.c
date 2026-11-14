#include "common.h"

/* Creates a record from the object's words and three flag bytes, then stores its derived word in the object. */
extern void *func_0053C920(int *arg0, int arg1, int arg2, int arg3);
extern void func_0053CAA8(u8 *arg0, s32 arg1, s32 arg2);

s32 D_00220DDC = 0;

void func_00540918(s32 *a, u8 b, u8 c, u8 d) {
    u8 tmp[16];
    s32 w;
    u32 *s;

    s = func_0053C920(D_00220DDC, 3, 0, 0);
    s[20] = a[18];
    w = a[0];
    func_0053CAA8(s, &w, 4);
    tmp[0] = b;
    func_0053CAA8(s, tmp, 1);
    tmp[0] = c;
    func_0053CAA8(s, tmp, 1);
    tmp[0] = d;
    func_0053CAA8(s, tmp, 1);
    a[12] = s[1] + (s[0] >> 14);
}
