#include "common.h"
extern s32 func_00502440(u8 *arg0);
extern s32 func_00502448(u8 *arg0);
extern f32 func_00502450(u8 *arg0);
extern u8 func_00502458(u8 *arg0);
extern u16 func_00502460(u8 *arg0);
extern u8 *func_00502478(u8 *arg0, u32 arg1);
extern u8 *func_005033D0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00503920(s32 id, s32 arg1);
extern s32 func_00504D68(s32 handle, s32 a, s32 b);
extern s32 func_00504E68(s32 handle, s32 a, s32 b);
extern void func_00504F68(s32, s32);
extern s32 func_005057E0(s32 handle, u8 *a, s32 b);
extern s32 func_00505DD0(u32 id, s32 amount);
extern s32 func_00506790(u32 id, s32 option, u32 color, f32 x, f32 y, f32 width, f32 height, f32 amount);

u8 *func_00502A88(u8 *data, s32 base, s32 arg2, s32 flags)
{
    s32 aligned = flags & 1;
    s32 mask;
    s32 id;
    f32 x, y, z, w;
    s32 a;
    s32 b;
    s32 c;
    s32 i;
    s32 j;
    u8 bits;
    u16 rows;
    u16 cols;
    u8 kind;
    u16 stride;
    s32 pitch;
    s32 pitch2;
    u8 *p = data;

    if (aligned) {
        p = func_00502478(func_00502478(data, 0x1000), 0x1000);
    }
    mask = func_00502448(p);
    p += 4;
    id = func_00502448(p) + base;
    p += 4;
    x = func_00502450(p);
    p += 4;
    y = func_00502450(p);
    p += 4;
    z = func_00502450(p);
    p += 4;
    w = func_00502450(p);
    p += 4;
    a = func_00502440(p);
    p += 4;
    b = func_00502448(p) != 0;
    p += 4;
    c = func_00502448(p);
    p += 4;
    func_00506790(id, 0, c, x, y, z, w, 0.0f);
    func_00503920(id, a);
    func_00504E68(id, 3, 3);
    func_005057E0(id, p, 0);
    for (i = 0; i < 8; i++) {
        func_00504D68(id, 1 << i, mask & (1 << i));
    }
    func_00504F68(id, b);
    bits = func_00502458(p + 0x15);
    if (!((bits >> 1) & 1)) {
        p[0x15] = bits | 2;
        *(u8 **)p = p + func_00502448(p);
        p += 4;
        *(u8 **)p = p + func_00502448(p);
        p += 4;
        *(u8 **)p = p + func_00502448(p);
        p += 4;
        *(u8 **)p = p + func_00502448(p);
        p += 4;
    } else {
        p += 16;
    }
    rows = func_00502460(p);
    p += 2;
    cols = func_00502460(p);
    p += 2;
    kind = func_00502458(p);
    p += 2;
    stride = func_00502460(p);
    p += 10;
    switch (kind) {
    case 0:
        pitch = stride * 4;
        p += rows * pitch + cols * 4;
        break;
    case 1:
        pitch2 = stride * 4;
        p += rows * pitch2 + cols * 2;
        for (j = 0; j < (cols * 2) % 4; j++) {
            p++;
        }
        break;
    }
    p = func_005033D0(p, base, id, flags);
    if (aligned) {
        p = func_00502478(p, 0x1000);
    }
    func_00505DD0(arg2, id);
    return p;
}
