/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_L00_004F1710(s32);

void func_L00_00513540(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = func_L00_004F1710(arg1);
}
