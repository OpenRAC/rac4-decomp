#include "common.h"

extern s32 D_1B7648_[];
#define D_1B7648 (D_1B7648_[0])

// Returns 0 when D_1B7648 is nonzero, otherwise -1.
s32 func_01ED4460(void) {
    return (D_1B7648 != 0) ? 0 : -1;
}
