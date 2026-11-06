#include "common.h"

extern s32 D_0021DE3C;

s32 func_00522518(u8 *arg0, s32 arg1, s32 arg2) {
    s32 special = 0;
    s32 kind = *(s32 *)(arg0 + 0x25CC);

    if (kind == 0x39 || kind == 0x8E ||
        (kind == 0x99 && (*(s32 *)(arg0 + 0x25D8) == 0x39 ||
                          *(s32 *)(arg0 + 0x25D8) == 0x8E))) {
        if (arg1 == 0x7A || arg1 == 0x7E || arg1 == 0x7B ||
            arg1 == 0x76 || arg1 == 0x94) {
            special = 1;
        }
    }
    if (special == 0 && *(s32 *)(arg0 + 0x25D4) == 0x14 &&
        (arg1 != 0x63 || arg2 != 2)) {
        return 0;
    }
    if ((D_0021DE3C == 2 || D_0021DE3C == 6) && arg2 != 2) {
        return 0;
    }
    if (special == 0 && *(f32 *)(arg0 + 0x2E20) == 0.0f &&
        (*(s32 *)(arg0 + 0x25D4) == 2 || *(s32 *)(arg0 + 0x25D4) == 7)) {
        if (arg1 != 6 && arg1 != 0x39 && arg1 != 0x76 &&
            arg1 != 0x7A && arg1 != 0x7B && arg1 != 0x7E &&
            arg1 != 0x6A && arg1 != 0x7F && arg1 != 0x81 &&
            arg1 != 0x99 && arg1 != 0x94) {
            return 0;
        }
    }
    return 1;
}
