#include "common.h"

typedef struct {
    s32 caption, icon, image;
} Row;
typedef struct {
    u8 unknown0[8];
    u32 icon;
    u32 color;
    s32 image;
    s32 label;
} Item;
typedef struct {
    u32 unknown0, sectorCount;
} Resource;
extern Row D_003D1CE8[];
extern s32 D_00221848;
extern u8 D_003097A8[];
extern Resource D_001CE158[];
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506000(u32, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
extern s32 func_005063C0(s32, u32);
extern s32 func_00506590(s32, u32);
extern void func_0049AA18(s32);
extern s32 func_0049A9D8(Resource *, s32);
extern s32 func_005071B8(u32, u32);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

void func_004B4F18(s32 index, Item *item)
{
    u32 offset = (u32)index * 12;
    s32 *caption = (s32 *)address(offset, (u32)D_003D1CE8);
    s32 *icon;
    s32 *image;
    s32 *cache;
    u32 handle;

    func_00506000(func_004A2798(&D_00221848, *caption), 1);
    icon = (s32 *)address(offset, address((u32)D_003D1CE8, 4));
    func_00506000(func_004A2798(&D_00221848, *icon), 1);
    handle = func_004A2798(&D_00221848, *caption);
    func_005062D0(handle, func_0045E850(item->label));
    func_005063C0(func_004A2798(&D_00221848, *icon), item->color);
    func_00506590(func_004A2798(&D_00221848, *icon), item->icon);
    image = (s32 *)address(offset, address((u32)D_003D1CE8, 8));
    func_00506000(func_004A2798(&D_00221848, *image), 1);
    cache = (s32 *)address((u32)index << 2, address((u32)D_003097A8, 0x168));
    if (*cache)
        func_0049AA18(*cache);
    *cache = func_0049A9D8((Resource *)((u32)D_001CE158 + ((u32)item->image << 3)), -1);
    func_00506590(func_004A2798(&D_00221848, *image), 1);
    func_005071B8(func_004A2798(&D_00221848, *image), *cache);
}
