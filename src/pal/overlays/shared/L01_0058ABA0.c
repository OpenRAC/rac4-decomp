/* cflags: -O2 -G8 */
#include "common.h"

void func_0045CE28(void);
extern u32 D_0021DFEC;
extern s32 D_00368BE8[];

void func_L01_0058ABA0(s32 enabled)
{
    if (enabled) {
        D_00368BE8[0] = 1;
        --D_0021DFEC;
    }
    func_0045CE28();
}
