#include "common.h"

// Advances the float at +8 of the object's +0xAC block by a cubic of the one at +0xC
// (0.6743 t + 0.4366 t^2 - 0.1099 t^3) and wraps it below 1.
void func_L01_003CFC58(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    f32 t = *(f32 *)(vars + 0xC);

    *(f32 *)(vars + 8) += t * 0.6743f + t * 0.4366f * t - t * 0.1099f * t * t;
    if (*(f32 *)(vars + 8) > 1.0f) {
        *(f32 *)(vars + 8) -= 1.0f;
    }
}
