#include "common.h"

/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * rac3-decomp/src/levels/shared/L01_0042B4F8.c func_L01_0042C370.
 * Independently reconstructed from RAC4 PAL retail. */

typedef struct {
    u8 prefix[0x8C];
    s16 count;
} State;
extern State D_00237100;
extern void func_00464E28(void);
void func_004644A8(void)
{
    while (D_00237100.count > 0) {
        func_00464E28();
        D_00237100.count--;
    }
}
