#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[691 - 576];
    u8 b2B3;
    u8 pad2B4[712 - 692];
    f32 f2C8;
    u8 pad2CC[728 - 716];
    f32 f2D8;
    u8 pad2DC[1136 - 732];
} Ent_524EC0;
extern void func_00453718(u8 *, void *, s32);
extern Ent_524EC0 D_00230280[];

/* from rac3-decomp's func_L01_003EE670 */
void func_L01_00524EC0(u8 *obj)
{
    Ent_524EC0 *ent = &D_00230280[*(s32 *)(obj + 148)];
    *(u128_t *)(obj + 48) = ent->v230;
    func_00453718(obj, ent->b200, 48);
    *(u16 *)(obj + 126) = 0;
    ent->b2B3 = 0;
    D_00230280[*(s32 *)(obj + 148)].f2D8 = 0.075f;
    D_00230280[*(s32 *)(obj + 148)].f2C8 = 0.075f;
}
