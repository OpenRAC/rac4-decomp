/* cflags: -G0 */
#include "common.h"

typedef struct {
    s32 count;
    s32 *fn;
} Table;

extern Table *D_004A03B4;
extern s32 func_0011A8A0(s32 *a, s32 *b);

/* Dispatch the pair by its first word through the registered table, or fall back
   to the default handler.  Returns the difference when the words do not match. */
s32 func_L00_0051C0C8(s32 **a, s32 **b)
{
    s32 i = *(s32 *)a;
    s32 d = i - *(s32 *)b;
    Table *t;

    if (d != 0) {
        return d;
    }
    t = D_004A03B4;
    if (t != 0 && i < t->count) {
        return ((s32 (*)(s32 *, s32 *))t->fn[i])(a[2], b[2]);
    }
    return func_0011A8A0(a[2], b[2]);
}
