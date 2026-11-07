/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern u16 D_00196760[];

void func_01EAECF0(s32 *arg0) {
    if (((u16) D_00196760[0] >> 8) == 0x23) {
        *arg0 = 1;
        return;
    }
    *arg0 = 0;
}
