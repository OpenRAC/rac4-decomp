#include "common.h"

/* Select the scalar result from the observed byte fields and word argument. */
s32 func_L00_006481C0(u8 *bytes, s32 word) {
    if (bytes[0] != 0) return 0x754B;
    if (word != 0) return 0x756E;
    if (bytes[2] != 0) return 0x7546;
    if (bytes[1] != 0) return 0x754A;
    return 0;
}
