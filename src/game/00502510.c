#include "common.h"

extern const u8 *func_00502478(const u8 *stream, u32 limit);
extern u32 func_00502448(const u8 *stream);
extern u32 func_00502440(const u8 *stream);
extern f32 func_00502450(const u8 *stream);
extern s32 func_00506B70(u32 handle);
extern s32 func_00503920(u32 handle, u32 color);
extern s32 func_00504D68(u32 handle, u32 mask, u32 value);
extern s32 func_00504F68(u32 handle, s32 visible);
extern void func_00505B70(s32 type, u32 handle);
extern s32 func_00505DD0(s32 parent, u32 child);
extern s32 func_00504238(u32 handle, f32 x, f32 y);
extern s32 func_005058E0(u32 handle, f32 x, f32 y);
extern const u8 *func_00503708(const u8 *stream, s32 stopAtMarker, u32 root,
                               u32 base, u32 parent, u32 flags, s32 attach);
extern const u8 *func_005033D0(const u8 *stream, u32 base, u32 parent, u32 flags);

const u8 *func_00502510(const u8 *stream, s32 root, u32 base, u32 parent, u32 flags, s32 attach)
{
    u32 mask;
    u32 handle;
    f32 x, y, width, height;
    u32 color;
    s32 visible;
    s32 bit;

    if (flags & 1) {
        stream = func_00502478(stream, 0x1000);
        stream = func_00502478(stream, 0x1000);
    }
    mask = func_00502448(stream);
    stream += 4;
    handle = func_00502448(stream) + base;
    stream += 4;
    x = func_00502450(stream);
    stream += 4;
    y = func_00502450(stream);
    stream += 4;
    width = func_00502450(stream);
    stream += 4;
    height = func_00502450(stream);
    stream += 4;
    color = func_00502440(stream);
    stream += 4;
    visible = func_00502448(stream) != 0;
    stream += 4;
    func_00506B70(handle);
    func_00503920(handle, color);
    for (bit = 0; bit < 8; ++bit) {
        u32 flag = 1u << bit;
        func_00504D68(handle, flag, mask & flag);
    }
    func_00504F68(handle, visible);
    if (attach) {
        if (root) {
            func_00505B70(parent, handle);
        } else {
            func_00505DD0(parent, handle);
        }
    }
    func_00504238(handle, x, y);
    func_005058E0(handle, width, height);
    stream = func_00503708(stream, 0, 0, base, handle, flags, 1);
    stream = func_005033D0(stream, base, handle, flags);
    if (!root) {
        stream = func_00502478(stream, 0x1000);
    }
    return stream;
}
