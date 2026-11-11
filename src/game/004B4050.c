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
extern Row D_003D1C78[];
extern s32 D_00221748;
extern u8 D_003096A8[];
extern Resource D_001CE0D8[];
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00504F68(u32, s32);
extern const char *func_0045E038(s32);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505328(s32, u32);
extern s32 func_005054F8(s32, u32);
extern void func_00499CE0(s32);
extern s32 func_00499CA0(Resource *, s32);
extern s32 func_00506120(u32, u32);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

void func_004B4050(s32 index, Item *item)
{
    u32 offset = (u32)index * 12;
    s32 *caption = (s32 *)address(offset, (u32)D_003D1C78);
    s32 *icon;
    s32 *image;
    s32 *cache;
    u32 handle;

    func_00504F68(func_004A1A60(&D_00221748, *caption), 1);
    icon = (s32 *)address(offset, address((u32)D_003D1C78, 4));
    func_00504F68(func_004A1A60(&D_00221748, *icon), 1);
    handle = func_004A1A60(&D_00221748, *caption);
    func_00505238(handle, func_0045E038(item->label));
    func_00505328(func_004A1A60(&D_00221748, *icon), item->color);
    func_005054F8(func_004A1A60(&D_00221748, *icon), item->icon);
    image = (s32 *)address(offset, address((u32)D_003D1C78, 8));
    func_00504F68(func_004A1A60(&D_00221748, *image), 1);
    cache = (s32 *)address((u32)index << 2, address((u32)D_003096A8, 0x168));
    if (*cache)
        func_00499CE0(*cache);
    *cache = func_00499CA0((Resource *)((u32)D_001CE0D8 + ((u32)item->image << 3)), -1);
    func_005054F8(func_004A1A60(&D_00221748, *image), 1);
    func_00506120(func_004A1A60(&D_00221748, *image), *cache);
}
