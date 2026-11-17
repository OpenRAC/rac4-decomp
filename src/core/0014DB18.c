#include "common.h"

void func_0014DB18(u8 *arg0, f32 fparg0) {
    f32 base = *(f32 *)arg0;
    f32 val = base;
    f32 t;

    if (val < 160000.0f) {
        f32 a = base * 1.00547f;
        f32 b = base + 1.125f;
        val = (b <= a) ? a : b;
    } else {
        val = base * (base < 500000.0f ? 1.001367f : 1.000684f);
    }
    if (fparg0 < base) {
        if (*(s8 *)(arg0 + 0x12) <= 0) {
            f32 u = base * 0.1f + (fparg0 + 1.0f) * 0.9f;
            val = (u <= val) ? u : val;
        }
        if (fparg0 <= base * 0.001f) {
            if (fparg0 < 1.0f) {
                t = base * 0.65f + (fparg0 + 1.0f) * 0.35f;
                val = (t <= val) ? t : val;
            } else {
                t = base * 0.4f + fparg0 * 0.6f;
                val = (t <= val) ? t : val;
            }
        } else if (fparg0 <= base * 0.01f) {
            t = base * 0.3f + fparg0 * 0.7f;
            val = (t <= val) ? t : val;
        } else {
            t = base * 0.2f + fparg0 * 0.8f;
            val = (t <= val) ? t : val;
        }
    } else if (*(s8 *)(arg0 + 0x13) == 0) {
        t = base * 0.75f + fparg0 * 0.25f;
        val = (val <= t) ? t : val;
    }
    if (val > 5059644.0f) {
        val = 5059644.0f;
    }
    if ((s8)arg0[0x12] <= 0) {
        arg0[0x12] += 1;
    }
    *(f32 *)arg0 = val;
}
