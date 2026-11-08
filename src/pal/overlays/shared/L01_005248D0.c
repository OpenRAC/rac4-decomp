#include "common.h"

typedef struct {
    u8 pad0[1036];
    f32 f1036;
    u8 pad1[0x470 - 1040];
} Ent_5248D0;
extern u8 D_00230380[];
extern void func_L01_0051F7E0(f32 a, f32 b, s32 a0, s32 a1);
extern void func_L01_00524958(void);
extern void func_L01_00537B20(s32 a0, void (*cb)(void));

/* PAL: from rac3-decomp's func_L03_003DA058 */
void func_L01_005248D0(s32 a0) {
    f32 v;
    v = ((Ent_5248D0 *)&D_00230380)[a0].f1036;
    if (v != 0.0f) {
        func_L01_0051F7E0(v * 0.35f + 0.0f, 0.005f, a0, 1);
        func_L01_00537B20(a0, func_L01_00524958);
    }
}
