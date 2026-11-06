#include "common.h"
typedef struct {
    s16 mode;
    s16 value;
    f32 factor;
    char pad[0x38];
    u8 alpha;
} State;
extern State D_00327A60;
void func_004EDCE8(void)
{
    f32 t = D_00327A60.value * D_00327A60.factor;
    if (D_00327A60.mode == 0 || D_00327A60.mode == 6 || D_00327A60.mode == 7)
        D_00327A60.alpha = (s32)((1.0f - t) * 128.0f);
    else if (D_00327A60.mode == 1)
        D_00327A60.alpha = (s32)(t * 128.0f);
}
