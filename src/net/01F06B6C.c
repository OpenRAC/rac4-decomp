/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern void func_0011A518(void *, s32, s32);
extern char D_0019E360[];
extern s8 func_01F06BE8(s8 *, s32 *);
void func_01F06B6C(s8 *arg0) {
    s32 n;
    s32 i;
    if (arg0 == NULL) {
        func_01F0C090(D_0019E360, 0xA5);
    }
    n = 0;
    i = 0;
    do {
        arg0[i] = func_01F06BE8(arg0, &n);
        i++;
    } while (arg0[n] != 0);
    func_0011A518(arg0 + i, 0, n - i);
}
