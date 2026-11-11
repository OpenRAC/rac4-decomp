/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct __attribute__((packed)) { s32 f0; s32 f4; } Type1;
/* Copy the stored fields when the object exists. */
s32 func_01EBE188(char *p, Type1 *out, s32 *other)
{
    if (!p) return 0xd2f2;
    *out = *(Type1 *)(p + 0x94);
    *other = *(s32 *)(p + 0x9c);
    return 0;
}
