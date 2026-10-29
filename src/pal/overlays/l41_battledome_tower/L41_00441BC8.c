#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} Pair;

extern Pair D_003982C8[];

extern s32 func_00454480(s32, s32, f32);
extern void func_L01_005A45A0(u8 *, u8 *, s32, s32, f32);

// Mixes two colour pairs from the table at 0x003982C8 (indices +4 and +8 of the object's +0xAC
// block) by the float at +0 (its absolute value when +4 is 10, else mapped to 0..1 and flipped
// when +8 < +4) and passes them to func_L01_005A45A0.
void func_L41_00441BC8(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    f32 t = *(f32 *)(vars + 0);
    s32 c;
    s32 c2;

    if (*(s32 *)(vars + 4) != 10) {
        t = (t + 1.0f) * 0.5f;
        if (*(s32 *)(vars + 8) < *(s32 *)(vars + 4)) {
            t = 1.0f - t;
        }
    } else if (t < 0.0f) {
        t = -t;
    }
    c = func_00454480(D_003982C8[*(s32 *)(vars + 4)].a, D_003982C8[*(s32 *)(vars + 8)].a, t);
    c2 = func_00454480(D_003982C8[*(s32 *)(vars + 4)].b, D_003982C8[*(s32 *)(vars + 8)].b, t);
    func_L01_005A45A0(arg0, vars + 0x34, c, c2, 0.28274336f);
}
