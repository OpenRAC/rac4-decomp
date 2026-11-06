#include "common.h"

s32 func_L01_004A7068(const u8 *object, const u8 *other)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    s16 class_id;

    if (other == NULL) {
        return 0;
    }
    class_id = *(const s16 *)(other + 0xBC);
    if (class_id == 0x1B35) {
        return state[0x674] == 7 ? 7 : 2;
    }
    if (class_id == 0x20D6) {
        return 6;
    }
    if (class_id == 0x268B) {
        return 1;
    }
    if (class_id == 0x260D) {
        return 5;
    }
    return state[0x674];
}
