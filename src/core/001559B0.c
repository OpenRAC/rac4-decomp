/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_00155850(u8 *);
/* Increment and wrap the byte counter. */
void func_001559B0(u8 *p)
{
    p[3]++;
    if (p[3] == 24) {
        p[3] = 0;
        func_00155850(p);
    }
}
