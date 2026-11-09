#include "common.h"

extern s32 D_00171D38[];
extern s32 D_002217E0;
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00497AE0(s32, s32, s32, f32, f32);

void func_004BA240(s32 arg0) {
    s32 a;
    if (arg0 != 0) {
        D_00171D38[4] += (s32)((f32)arg0 * 102.4f);
        if (D_00171D38[4] > 0x400 || D_00171D38[4] < 0) {
            func_00497980(4);
        } else {
            func_00497980(0x11);
        }
        {
            s32 v = D_00171D38[4];
            if (v > 0x400) {
                v = 0x400;
            }
            if (v < 0) {
                v = 0;
            }
            D_00171D38[4] = v;
        }
    }
    a = func_004A1A60(&D_002217E0, 0x1C);
    func_00497AE0(a, func_004A1A60(&D_002217E0, 0x1D), 0, (f32)D_00171D38[4] * 0.0009765625f, 0.0f);
}
