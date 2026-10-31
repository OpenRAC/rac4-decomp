#include "common.h"

s32 func_004FC650(void);
extern s32 D_00171B40_[];
#define D_00171B40 (D_00171B40_[0])

// Returns 0 for a null arg0, otherwise 1 when D_00171B40 (or func_004FC650 when arg0[0] is 0xC) is not below arg0[2].
s32 func_004E6FA0(s32 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if (arg0[0] == 0xC) {
        return func_004FC650() >= arg0[2];
    }
    return D_00171B40 >= arg0[2];
}
