#include "common.h"

typedef struct {
    u8 pad0[8];
    u8 f8;
} S_61E3E0;

/* from rac3-decomp's func_L03_0032C8F8 */
s32 func_L00_0061E3E0(S_61E3E0 *s) {
    if (s->f8 != 0) {
        s->f8 = 0;
        return 1;
    }
    return 0;
}
