#include "common.h"

typedef struct {
    s16 id;
    u8 pad2[0x12];
    s32 unk14;
    s32 timer;
} Slot;
extern Slot D_00308460[64];

void func_004A9C98(void)
{
    Slot *slot = D_00308460;

    do {
        slot->id = -1;
        slot->unk14 = 0;
        slot++;
    } while ((s32)slot < (s32)(D_00308460 + 64));
}
