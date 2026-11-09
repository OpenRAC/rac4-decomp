#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
} Data;
typedef struct {
    s32 f0;
    s32 menu;
    Data *data;
} Item;
typedef struct {
    char pad[0x54];
    s32 index;
} List;

extern s32 func_0045E038(s32);
extern void func_004979A8(void *, s32, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504F68(u32, s32), func_00505238(u32, const char *), func_00505328(u32, u32);
extern s32 func_005054F8(u32 id, s32 amount);
extern char D_0030D194[][16];

void func_004C8830(List *list, Item *item, s32 index)
{
    Data *data = item->data;

    func_00504F68(func_004A1A60(&item->menu, 7), data->f0 == 0);
    func_00504F68(func_004A1A60(&item->menu, 2), data->f0 != 0);
    if (data->f0 == 0) {
        func_00505238(func_004A1A60(&item->menu, 8), (const char *)func_0045E038(data->f14));
        return;
    }
    func_005054F8(func_004A1A60(&item->menu, 5), 30004);
    func_00505238(func_004A1A60(&item->menu, 3), (const char *)func_0045E038(data->f14));
    if (data->f18 > 0) {
        func_00504F68(func_004A1A60(&item->menu, 4), 1);
        func_005054F8(func_004A1A60(&item->menu, 4), data->f18);
    } else {
        func_00504F68(func_004A1A60(&item->menu, 4), 0);
    }
    if (data->f8 == 0) {
        func_00505238(func_004A1A60(&item->menu, 6), (const char *)func_0045E038(0x30DC));
    } else {
        char *buf = D_0030D194[index];
        func_004979A8(buf, data->f8, 0);
        func_00505238(func_004A1A60(&item->menu, 6), buf);
    }
    if (data->f20 != 0) {
        func_00505328(func_004A1A60(&item->menu, 5), 0x80808080);
        func_00505328(func_004A1A60(&item->menu, 4), 0x80808080);
        func_00505328(func_004A1A60(&item->menu, 3), 0x80808080);
        if (data->f8 == 0) {
            func_00505328(func_004A1A60(&item->menu, 6), 0x8040D0D0);
        } else {
            func_00505328(func_004A1A60(&item->menu, 6), 0x80D0D0D0);
        }
    } else {
        func_00505328(func_004A1A60(&item->menu, 5), 0x80404040);
        func_00505328(func_004A1A60(&item->menu, 4), 0x80404040);
        func_00505328(func_004A1A60(&item->menu, 3), 0x80404040);
        func_00505328(func_004A1A60(&item->menu, 6), 0x80404080);
    }
    if (list->index == index) {
        func_00505328(func_004A1A60(&item->menu, 5), 0x80D0D0D0);
        func_00505328(func_004A1A60(&item->menu, 3), 0x80D0D0D0);
        func_00505328(func_004A1A60(&item->menu, 4), 0x80D0D0D0);
    }
}
