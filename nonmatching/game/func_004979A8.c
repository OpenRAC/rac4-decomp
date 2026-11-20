/* Not matching yet: BYTES 0/308, exact only with inline asm (blezl/sub abs), which matched C may not use (tools/check_func.py func_004979A8). Not part of the build. */
#include "common.h"

extern char D_0021F568[];
extern char D_0021F570[];
extern char D_0021F580[];
extern char D_003D1240[];
extern s32 func_0011D920(char *, const char *, ...);

/* Retail's abs is `blezl x; sub x, $0, x`, which GCC never emits (its abs is bltzl + negu). */
static inline s32 abs_s32(s32 x)
{
    __asm__(".set push\n\t.set noreorder\n\tblezl %0, 1f\n\tsub %0, $0, %0\n\t.set pop\n1:" : "+r"(x));
    return x;
}

void func_004979A8(char *buf, s32 value, s32 show_plus)
{
    s32 sign;

    if (value >= 0) {
        sign = show_plus ? '+' : ' ';
    } else {
        sign = '-';
    }
    value = abs_s32(value);
    if (value < 1000) {
        func_0011D920(buf, D_0021F568, sign, value);
    } else if (value < 1000000) {
        func_0011D920(buf, D_0021F570, sign, value / 1000, value % 1000);
    } else if (value < 1000000000) {
        func_0011D920(buf, D_0021F580, sign, value / 1000000, value % 1000000 / 1000, value % 1000);
    } else {
        func_0011D920(buf, D_003D1240, sign, value / 1000000000, value % 1000000000 / 1000000,
                      value % 1000000 / 1000, value % 1000);
    }
}
