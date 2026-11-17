/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct { char _p[0x15C]; char name[1]; } Type1;
extern s32 func_0011AB04(char *);
extern s32 func_0011D878();
extern u8 D_00191F01[];
s32 func_01E9AD78(s32 a0, s32 a1, s32 a2, s32 a3, Type1 *p) {
    char *s = p->name;
    s32 n = func_0011AB04(s);
    while (n != 0 && (D_00191F01[(s32)s[n - 1]] & 8)) {
        s[--n] = 0;
    }
    return func_0011D878(a0, a1, a2, s);
}
