#include "common.h"
typedef struct Data Data;
typedef struct {
    char pad[0x14];
    s32 (*supports)(Data *, u32);
} Vtable;
typedef struct {
    f32 x, y;
} Pair;
struct Data {
    s32 f0, f4;
    Vtable *v;
    s32 fC;
    f32 f10;
    Pair f14, f1C, f24;
    s32 f2C, f30, f34, f38, f3C;
    f32 f40;
    u32 f44, f48, f4C;
    u16 f50, f52;
    u8 f54, f55, f56, f57;
    void *f58;
};
extern s32 func_0050BFA8(Data *, Data *);
s32 func_0050DB80(Data *dst, Data *src)
{
    if (src->v->supports(src, 1)) {
        func_0050BFA8(dst, src);
        dst->fC = src->fC;
        dst->f10 = src->f10;
        dst->f14 = src->f14;
        dst->f1C = src->f1C;
        dst->f24 = src->f24;
        dst->f30 = src->f30;
        dst->f34 = src->f34;
        dst->f40 = src->f40;
        dst->f44 = src->f44;
        dst->f48 = src->f48;
        dst->f4C = src->f4C;
        dst->f50 = src->f50;
        dst->f52 = src->f52;
        dst->f54 = src->f54;
        dst->f55 = src->f55;
        dst->f56 = src->f56;
        dst->f58 = src->f58;
        return 1;
    }
    return 0;
}
