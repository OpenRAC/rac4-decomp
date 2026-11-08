/* cflags: -G0 */
#include "common.h"

// Clamp the slot index into [0, count] and mirror it into the active slot.
void func_L00_00713CF0(u8 *p, s32 index) {
    if (index == -1) {
        *(s32 *)(p + 0x10A60) = 0;
    } else if (index == -2) {
        *(s32 *)(p + 0x10A60) = *(s32 *)(p + 0x85C) - 1;
    } else if (index >= 0 && *(s32 *)(p + 0x85C) >= index) {
        *(s32 *)(p + 0x10A60) = index;
    }
    *(s32 *)(p + 0x10A64) = *(s32 *)(p + 0x10A60);
}
