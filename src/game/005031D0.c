#include "common.h"
extern s32 func_00502440(u8 *arg0);
extern s32 func_00502448(u8 *arg0);
extern f32 func_00502450(u8 *arg0);
extern u8 *func_00502478(u8 *arg0, u32 arg1);
extern u8 *func_005033D0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00503920(s32 id, s32 arg1);
extern s32 func_00504D68(s32 handle, s32 a, s32 b);
extern void func_00504F68(s32, s32);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505DD0(u32 id, s32 amount);
extern s32 func_00506860(s32 a, u8 *b, s32 c, f32 x, f32 y, f32 z, f32 w);

u8 *func_005031D0(u8 *data, s32 base, s32 arg2, s32 flags)
{
    s32 aligned = flags & 1;
    s32 mask;
    s32 id;
    f32 x, y, z, w;
    s32 a;
    s32 b;
    s32 c;
    s32 i;
    u8 *next;
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
    p += 8;
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
    next = p;
    p = func_00502478(p, 0x20);
    func_00506860(id, next, c, x, y, z, w);
    func_00503920(id, a);
    for (i = 0; i < 32; i++) {
        func_00504D68(id, 1 << i, mask & (1 << i));
    }
    func_00504F68(id, b);
    func_00505040(id, 1);
    p = func_005033D0(p, base, id, flags);
    if (aligned) {
        p = func_00502478(p, 0x1000);
    }
    func_00505DD0(arg2, id);
    return p;
}
