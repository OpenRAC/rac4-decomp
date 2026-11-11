/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_0016FC40;
extern s32 func_00129638(s32, s32);
/* Clear state and dispatch mode one. */
void func_00155BC8(s32 a)
{
 if (a == 1) { D_0016FC40 = 0; func_00129638(1, 0); }
}
