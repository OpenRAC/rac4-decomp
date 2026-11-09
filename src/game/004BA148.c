#include "common.h"

typedef struct Type1 {
    s32 f0, f4, f8, fC;
} Type1;
extern Type1 D_00171D38[];
extern s32 D_002217E0;
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00497AE0(s32, s32, s32, f32, f32);

void func_004BA148(s32 arg0) {
    s32 a;
    s32 v;
    if (arg0 != 0) {
        D_00171D38[0].fC += (s32)((f32)arg0 * 102.4f);
        if ((u32)D_00171D38[0].fC > 0x400) {
            func_00497980(4);
        } else {
            func_00497980(0x11);
        }
        v = D_00171D38[0].fC;
        if (v > 0x400) v = 0x400;
        if (v < 0) v = 0;
        D_00171D38[0].fC = v;
    }
    a = func_004A1A60(&D_002217E0, 0x1F);
    func_00497AE0(a, func_004A1A60(&D_002217E0, 0x20), 0, (f32)D_00171D38[0].fC * (1.0f / 1024.0f), 0.0f);
}
