/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_0011A2DC(u8 *, s32, s32);
extern u8 D_004A1A30[];

s32 func_L00_00528BC8(s32 value) {
    u8 *entry;
    s32 index;
    for (entry = D_004A1A30, index = 0; index < 0x10; index++, entry += 8) {
        if (func_0011A2DC(entry, value, 8) == 0) return 1;
    }
    return 0;
}
