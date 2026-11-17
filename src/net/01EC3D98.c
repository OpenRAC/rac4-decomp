/* cflags: @ee32-040921 -O2 -G8 */
#include "common.h"

extern s32 func_01EA7D70(s32 arg0);
extern s32 func_01EC3460();
extern s32 func_01EC3498(void);

/* Fetch a network value, initializing it if it is not ready yet. */
s32 func_01EC3D98(s32 arg0)
{
    s32 r = func_01EC3460();
    s32 x;

    if (r != 0) {
        return r;
    }
    x = func_01EA7D70(arg0);
    func_01EC3498();
    return x;
}
