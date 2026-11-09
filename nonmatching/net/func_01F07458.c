/* Not matching yet: BYTES 2/116 (tools/try_func.py func_01F07458 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_01F073AC(s32 a0, s32 key);

/* Look the object up and let its vtable's +0xC entry run with the three
   arguments; the looked-up object is the result. */
s32 func_01F07458(s32 a0, s32 *obj, s32 a2, s32 a3)
{
    s32 *p = (s32 *)func_01F073AC(a0, *obj);

    if (p != 0) {
        (*(s32 (*)(s32 *, s32 *, s32, s32))(*(s32 *)(*p + 0xC)))(p, obj, a2, a3);
    }
    return (s32)p;
}
