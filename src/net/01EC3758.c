/* cflags: @ee32-040921 -O2 -G8 */
#include "common.h"

extern s32 func_01EC3460();
extern s32 func_01EC5070(u32 i, s32 a1);
extern void func_01EC3498();
extern u32 D_00169544;

/* Reset every entry of the global table and then the table itself. */
s32 func_01EC3758(void)
{
    s32 r = func_01EC3460();
    u32 i;

    if (r != 0) {
        return r;
    }
    for (i = 0; i < D_00169544; i++) {
        func_01EC5070(i, 0);
    }
    func_01EC3498();
    return 0;
}
