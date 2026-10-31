#include "common.h"

extern s32 D_1B7648_[];
#define D_1B7648 (D_1B7648_[0])

// Returns 0 if the word at D_1B7648 is nonzero, otherwise -1.
s32 func_01ED4438(void) {
    s32 r = -1;
    if (D_1B7648 != 0) {
        r = 0;
    }
    return r;
}
