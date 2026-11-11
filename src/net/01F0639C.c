/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x254];
    s32 f254;
    s32 f258;
    char _p25C[0x4];
    s32 f260;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E200[];

f32 func_01F0639C(Type1 *arg0) {
    s32 n = arg0->f258;
    s32 m = arg0->f254;

    if (m < n) {
        n = m;
    }
    if (arg0->f260 < 0) {
        func_01F0C090(D_0019E200, 0x2C5);
    }
    if (arg0->f260 <= 0) {
        return 0.0f;
    }
    return (f32)arg0->f260 / (f32)n;
}
