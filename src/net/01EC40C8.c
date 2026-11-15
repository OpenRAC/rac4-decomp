/* cflags: @ee32-040921 -O2 -G8 */
#include "common.h"

extern s32 func_01EC3460();
extern s32 func_01EC3498();
extern s32 func_01EC5280(s32 a0);

s32 func_01EC40C8(s32 a0, s32 a1)
{
    s32 r = func_01EC3460();
    s32 s;
    u32 i;
    s32 *p;

    if (r != 0) {
        return r;
    }
    s = 2;
    r = func_01EC5280(a0);
    if (r != 0) {
        p = (s32 *)(r + 0x94);
        i = 0;
        do {
            if (*p != 0) {
                *(s32 *)(*p + 0x40) = a1;
            }
            p++;
            i++;
        } while (i < 2);
        s = 0;
    }
    func_01EC3498();
    return s;
}
