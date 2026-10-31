#include "common.h"

extern s32 func_004CAF30(s32 arg0);

// Loop through indices 0-3, return 1 if func_004CAF30 returns nonzero for any, else 0.
s32 func_004CAF50(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_004CAF30(i) != 0) {
            return 1;
        }
    }
    return 0;
}
