/* Reference: OpenRAC/rac2-decomp @ 99f35ac2c084fc59cdf3d631f8f960a825e7a49c; func_L00_00322EC8 (src/levels/shared/L00_00316F60.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

typedef struct {
    u8 unknown0[0x148];
    s32 count;
    s32 active;
} Owner;

typedef struct {
    u8 unknown0[0x120];
    void *slots[0];
} SlotOwner;

extern void func_0046C6B0(void *);

void func_00479E28(Owner *owner)
{
    s32 index;

    if (owner->active != 0) {
        for (index = 0; index < owner->count; index++) {
            if (((SlotOwner *)owner)->slots[index] != 0) {
                func_0046C6B0(((SlotOwner *)owner)->slots[index]);
                ((SlotOwner *)owner)->slots[index] = 0;
            }
        }
        owner->active = 0;
    }
}
