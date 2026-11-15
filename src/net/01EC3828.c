/* cflags: @ee32-040921 -O2 -G8 */
#include "common.h"

extern s32 func_01EC3460();
extern s32 func_01EC3498(void);
extern s32 func_01EC47A8(u32, s32);
extern s32 func_01EC51F8(u32);
extern u32 D_00169544;

s32 func_01EC3828(s32 arg0)
{
    s32 found = 0;
    s32 r = func_01EC3460();
    u32 i;

    if (r != 0) {
        return r;
    }
    i = 0;
    if (D_00169544 != 0) {
        do {
            if (func_01EC51F8(i) != 0) {
                found = func_01EC47A8(i, arg0);
            }
            i++;
        } while (i < D_00169544 && found == 0);
    }
    func_01EC3498();
    return found;
}
