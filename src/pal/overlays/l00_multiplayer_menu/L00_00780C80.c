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

/* Lower bound of a profile threshold bucket: 0 for bucket 1, otherwise the preceding threshold. */
f32 func_L00_0077FA18(s32 index)
{
    if (index == 1) {
        return 0.0f;
    }
    return (f32)((const ProfileThresholdView *)&D_001721E0)->thresholds[index - 2];
}
