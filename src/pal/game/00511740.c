#include "common.h"

typedef struct {
    char pad0[0x16];
    s16 limit;
} Emitter;

typedef struct {
    char pad0[0x14];
    f32 scaleX;
    f32 scaleY;
    f32 f1C;
    f32 f20;
    char pad24[0xC];
    u32 color;
    char pad34[0xC];
    f32 f40;
    f32 f44;
    char pad48[4];
    Emitter *emitter;
} Object;

extern u8 D_00171E6B[];
extern s32 *D_0021DE2C;
extern f32 D_00220B5C;
extern f32 D_00220B60;
extern f32 D_00220B64;
extern f32 D_00220B68;
extern f32 D_00220B7C;
extern f32 D_00220B80;

extern f32 func_004543B8(f32);
extern void func_004EF280(void *, s32, s32, f32, f32, f32, u32, f32);

static inline void draw(Emitter *emitter, f32 x, f32 y, u32 color,
                        f32 first, f32 second, f32 parameter, f32 time)
{
    s32 frame, limit, ix, iy;
    f32 fraction, third;
    if (emitter == 0)
        return;
    frame = (s32)time;
    limit = emitter->limit;
    fraction = time - (f32)frame;
    if (frame >= limit)
        return;
    if (fraction >= 0.001f && frame + 1 >= limit)
        return;
    x = (x + D_00220B64) * D_00220B7C;
    y = (y + D_00220B68) * D_00220B80;
    first *= D_00220B5C;
    second *= D_00220B60;
    ix = (s32)x;
    iy = (s32)y;
    third = func_004543B8(parameter);
    func_004EF280(emitter, ix, iy, first, second, third, color, time);
}
void func_00511740(Object *obj, const f32 *rect, f32 alpha)
{
    f32 scale, x0, y0, x, y;
    u32 color;
    if (obj->emitter == 0)
        return;
    scale = obj->scaleX;
    if (D_00171E6B[0] && scale == 6.5f && *D_0021DE2C == 2)
        scale = 10.136f;
    x = (rect[2] - rect[0]) * scale + rect[0];
    y = (rect[3] - rect[1]) * obj->scaleY + rect[1];
    color = obj->color;
    if (alpha < 0.999f)
        color = (color & 0xFFFFFF) | ((u32)(s32)((f32)(color >> 24) * alpha) << 24);
    draw(obj->emitter, x, y, color, obj->f1C, obj->f20, obj->f40, obj->f44);
}
