/* Not matching yet: SIZE ours 164 / retail 172 (tools/try_func.py func_01F073AC --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(const char *a0, const char *a1);

s32 *func_01F073AC(s32 *arg0, const char *arg1)
{
    s32 i = 0;
    s32 *found = 0;
    s32 *o;

    for (i = 0; i < 8 && found == 0; i++) {
        if (arg0[i * 2] != 0) {
            if (func_0011A8A0((const char *)arg0[i * 2 + 1], arg1) == 0) {
                o = (s32 *)arg0[i * 2];
                if (((s32 (*)(s32 *))(*(s32 **)o)[5])(o) == 0)
                    found = (s32 *)arg0[i * 2];
            }
        }
    }
    return found;
}
