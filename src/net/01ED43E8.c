/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011AFC8(void *, const void *, s32);
extern char D_00169C48[];
/* Copies a bounded string and terminates it. */
s32 func_01ED43E8(char *p, s32 n)
{
    func_0011AFC8(p, D_00169C48, n);
    p[n-1]=0;
    return 0;
}
