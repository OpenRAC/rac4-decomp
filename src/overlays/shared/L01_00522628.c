#include "common.h"

typedef struct {
    u8 pad0[1036];
    f32 f1036;
    u8 pad1[1136 - 1040];
} Ent_522628;
extern Ent_522628 D_00230280[];
extern void func_L01_0051D538(f32 a, f32 b, s32 a0, s32 a1);
extern void func_L01_005226B0(void);
extern void func_L01_00535298(s32 a0, void (*cb)(void));

/* from rac3-decomp's func_L03_003DA058 */
void func_L01_00522628(s32 a0) {
    Ent_522628 *e = D_00230280 + a0;
    f32 v = e->f1036;
    if (v != 0.0f) {
        func_L01_0051D538(v * 0.35f + 0.0f, 0.005f, a0, 1);
        func_L01_00535298(a0, func_L01_005226B0);
    }
}
