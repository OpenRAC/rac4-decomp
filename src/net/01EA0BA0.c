/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct __attribute__((packed)) { s32 f0; s32 f4; } Type1;
extern s32 *D_00167EFC;
/* Copy the stored value if output exists. */
s32 func_01EA0BA0(Type1 *out)
{
    if (!out) return 23;
    *out = *(Type1 *)((char *)D_00167EFC + 0x18);
    return 0;
}
