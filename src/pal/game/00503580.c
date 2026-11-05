#include "common.h"

extern const u8 *func_005034E8(const u8 *stream, u32 limit);
extern u32 func_005034B8(const u8 *stream);
extern u32 func_005034B0(const u8 *stream);
extern f32 func_005034C0(const u8 *stream);
extern s32 func_00507C08(u32 handle);
extern s32 func_005049B8(u32 handle, u32 color);
extern s32 func_00505E00(u32 handle, u32 mask, u32 value);
extern s32 func_00506000(u32 handle, s32 visible);
extern void func_00506C08(s32 type, u32 handle);
extern s32 func_00506E68(s32 parent, u32 child);
extern s32 func_005052D0(u32 handle, f32 x, f32 y);
extern s32 func_00506978(u32 handle, f32 x, f32 y);
extern const u8 *func_005047A0(const u8 *stream, s32 stopAtMarker, u32 root,
                               u32 base, u32 parent, u32 flags, s32 attach);
extern const u8 *func_00504468(const u8 *stream, u32 base, u32 parent, u32 flags);

const u8 *func_00503580(const u8 *stream, s32 root, u32 base, u32 parent, u32 flags, s32 attach)
{
    u32 mask;
    u32 handle;
    f32 x, y, width, height;
    u32 color;
    s32 visible;
    s32 bit;

    if (flags & 1) {
        stream = func_005034E8(stream, 0x1000);
        stream = func_005034E8(stream, 0x1000);
    }
    mask = func_005034B8(stream);
    stream += 4;
    handle = func_005034B8(stream) + base;
    stream += 4;
    x = func_005034C0(stream);
    stream += 4;
    y = func_005034C0(stream);
    stream += 4;
    width = func_005034C0(stream);
    stream += 4;
    height = func_005034C0(stream);
    stream += 4;
    color = func_005034B0(stream);
    stream += 4;
    visible = func_005034B8(stream) != 0;
    stream += 4;
    func_00507C08(handle);
    func_005049B8(handle, color);
    for (bit = 0; bit < 8; ++bit) {
        u32 flag = 1u << bit;
        func_00505E00(handle, flag, mask & flag);
    }
    func_00506000(handle, visible);
    if (attach) {
        if (root) {
            func_00506C08(parent, handle);
        } else {
            func_00506E68(parent, handle);
        }
    }
    func_005052D0(handle, x, y);
    func_00506978(handle, width, height);
    stream = func_005047A0(stream, 0, 0, base, handle, flags, 1);
    stream = func_00504468(stream, base, handle, flags);
    if (!root) {
        stream = func_005034E8(stream, 0x1000);
    }
    return stream;
}
