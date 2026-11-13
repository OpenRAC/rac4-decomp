/* cflags: @ee296 -O2 -G0 */
#include "common.h"

void func_01EEEDA0(u8 *arg0, void **arg1, void **arg2, s32 *arg3, void **arg4) {
    *arg1 = arg0 + 0x30DC;
    *arg2 = arg0 + 0x30FC;
    *arg4 = arg0 + 0x311C;
    *arg3 = *(s32 *)(arg0 + 0x312C);
}
