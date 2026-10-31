#include "common.h"
typedef int s128 __attribute__((mode(TI)));
#define FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))

/* Copy 16 bytes and a scalar when the linked flag and source are present. */
s32 func_L01_0044AD30(void *arg0)
{
    void *source;
    if (FIELD(FIELD(arg0, void *, 0xAC), u8, 0x104) == 0) {
        goto block_4;
    }
    source = FIELD(arg0, void *, 0xB8);
    if (source == NULL) {
        goto block_3;
    }
    goto block_5;
block_3:
block_4:
    return 0;
block_5:
    FIELD(arg0, s128, 0x10) = FIELD(source, s128, 0x10);
    FIELD(arg0, f32, 0xF8) = FIELD(source, f32, 0xF8);
    return 1;
}
