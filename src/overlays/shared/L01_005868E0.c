/* cflags: -O2 -G8 */
#include "common.h"

void func_00568380(void);
extern u32 D_0021DF64;
extern s32 D_00368BE8[];

void func_L01_005868E0(s32 enabled)
{
    if (enabled) {
        D_00368BE8[0] = 1;
        --D_0021DF64;
    }
    func_00568380();
}
