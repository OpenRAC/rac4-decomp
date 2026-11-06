#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
typedef union {
    f32 f[4];
    Quadword q;
} Vector;
extern f32 func_00454328(f32 angle, f32 delta);

Vector *func_L01_00503B88(Vector *output, const u8 *object, f32 *factor)
{
    u8 *state = *(u8 **)(object + 0xAC);

    if (object[0x69] == 2 && object[0x20] == 5) {
        Vector result;
        f32 first;
        f32 second;

        if (factor)
            *factor = 0.5f;
        first = func_00454328(*(f32 *)(state + 0x174), *(f32 *)(state + 0x194));
        second = func_00454328(*(f32 *)(state + 0x178), *(f32 *)(state + 0x198));
        result.f[1] = first;
        result.f[2] = second;
        result.f[0] = 0.0f;
        result.f[3] = 0.0f;
        output->q = result.q;
    } else if (object[0x69] == 3 && object[0x20] == 6) {
        if (factor)
            *factor = 0.5f;
        output->q = *(Quadword *)(state + 0x170);
    } else {
        output->q = *(Quadword *)(state + 0x170);
    }
    return output;
}
