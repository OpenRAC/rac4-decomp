/* Not matching yet: SIZE ours 100 / retail 112 (tools/try_func.py func_L00_00713CF0 --diff). Not part of the build. */
#include "common.h"

// Clamp the slot index into [0, count] and mirror it into the active slot.
void func_L00_00713CF0(u8 *p, s32 index) {
    s32 count = *(s32 *)(p + 0x85C);

    if (index == -1) {
        *(s32 *)(p + 0x10A60) = 0;
    } else if (index == -2) {
        *(s32 *)(p + 0x10A60) = count - 1;
    } else if (index >= 0 && count >= index) {
        *(s32 *)(p + 0x10A60) = index;
    }
    *(s32 *)(p + 0x10A64) = *(s32 *)(p + 0x10A60);
}
