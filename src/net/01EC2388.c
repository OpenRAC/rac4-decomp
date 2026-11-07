/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_0011A518(s32 *, s32, s32);
s32 func_01EBDCA8(s32);
extern s32 D_001B6898[];

s32 func_01EC2388(void) {
    func_01EBDCA8(D_001B6898[0]);
    func_0011A518(D_001B6898, 0, 0x108);
    return 0;
}
