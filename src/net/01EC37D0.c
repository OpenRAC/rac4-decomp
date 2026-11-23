/* cflags: @ee32-040921 -O2 -G8 */
#include "common.h"

extern s32 func_01EC3460(void);
extern s32 func_01EC3498(void);
extern s32 func_01EC47A8(u32, s32);

s32 func_01EC37D0(s32 arg0, s32 arg1)
{
    s32 r = func_01EC3460();
    s32 s;

    if (r != 0) {
        return r;
    }
    s = func_01EC47A8(arg0, arg1);
    func_01EC3498();
    return s;
}
