#include "common.h"
#include "pal/profile_001721E0.h"

typedef struct {
    Type4 prefix;
    u8 pad[0x15F0 - sizeof(Type4)];
    s16 thresholds[10];
} ProfileThresholdView;

s32 func_L00_00780C80(f32 value)
{
    const ProfileThresholdView *profile = (const ProfileThresholdView *)&D_001721E0;
    const s16 *threshold = profile->thresholds;
    s32 i;

    for (i = 0; i < 10; i++, threshold++) {
        if (value < (f32)*threshold) {
            return i + 1;
        }
    }

    return 10;
}
