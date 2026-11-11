/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u32 D_0016E3A8;
typedef struct { f32 f0; f32 f4; const char *f8; u32 fc; } Type1;
/* Initialize an entry and increment its sequence counter. */
void func_01F02184(char *p, Type1 *out)
{
    u32 old;
    out->f0 = *(f32 *)(p + 0xe0);
    out->f8 = 0;
    old = D_0016E3A8++;
    out->fc = old;
}
