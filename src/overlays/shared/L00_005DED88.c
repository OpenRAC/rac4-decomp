#include "common.h"

extern s32 D_002224A4;

/* 0 for id 0xFF, else whether id is at least D_002224A4. */
s32 func_L00_005DED88(s32 i) {
    if (i == 0xFF) {
        return 0;
    }
    return i >= D_002224A4;
}
