#include "common.h"

#include "pal/profile_001721E0.h"
s32 D_0021E030 = 0;

// PAL version of func_0015AD70: increments a global counter and adds 20 (one 50 Hz frame in
// ms) to the s32 at 0x1721E0+0x218; the US build spreads 16.67 ms as 16 or 17 with count % 3.
void func_0015ADA0(void) {
    s32 count = D_0021E030 + 1;
    D_0021E030 = count;
    D_001721E0.region20.words.f218 = D_001721E0.region20.words.f218 + 0x14;
}
