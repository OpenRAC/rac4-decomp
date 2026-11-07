#include "common.h"

// Sets (ARG1 != 0) or clears the bits of ARG0 in the word at ARG2->0x450, when the
// word at ARG2->0x468 is 2. Each arm re-reads the field, as retail does.
void func_01EA5160(s32 arg0, s32 arg1, u8 *arg2) {
    if (arg2 != NULL && *(s32 *)(arg2 + 0x468) == 2) {
        if (arg1 != 0) {
            *(s32 *)(arg2 + 0x450) = *(s32 *)(arg2 + 0x450) | arg0;
            return;
        }
        *(s32 *)(arg2 + 0x450) = *(s32 *)(arg2 + 0x450) & ~arg0;
    }
}
