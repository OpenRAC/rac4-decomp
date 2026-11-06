/* Not matching yet on PAL: SIZE ours 148 / disc 204 (tools/check_func.py --version pal func_004E8378 --diff). Not part of the build. */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"
extern u32 D_10008000;
extern u32 D_10008020;
extern u32 D_10008030;

s32 D_0022078C = 0;

void func_00453DF8(s32 arg0);

void func_004E8378(s32 arg0)
{
    if (arg0 == D_0022078C) {
        return;
    }
    while ((D_10008000 & 0x100) != 0) {
        func_00453DF8(0x10);
    }
    D_10008020 = 0;
    D_10008030 = arg0 & 0x0FFFFFFF;
    D_10008000 = 0x145;
    D_0022078C = arg0;
    while ((D_10008000 & 0x100) != 0) {
        func_00453DF8(0x10);
    }
}
