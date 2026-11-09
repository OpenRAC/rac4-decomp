#include "common.h"

typedef struct {
    char pad[0x98];
    s32 flags;
    f32 f9C;
    char tail[0x18];
} Type1;
extern Type1 D_00308208[];
extern f32 func_004760C0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern u8 func_00498E38(s32 arg0);
extern s32 func_00506BB8(void);

void func_004AA180(void)
{
    s32 index = func_00506BB8();
    Type1 *p = (Type1 *)((u32)index * 0xB8 + (u32)D_00308208);
    if (func_004760C0(&p->f9C, (f32)func_00498E38(index), 0.0f, 0.24000001f) != 0.0f) {
        D_00308208[index].flags |= 0x100;
    }
}
