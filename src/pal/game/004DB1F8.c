#include "common.h"

typedef struct Item {
    s32 kind;
    s32 id;
    s32 cost;
    s32 unknownC;
    s32 unknown10;
    s32 label;
    s32 unknown18;
    s32 unknown1C;
    s32 enabled;
} Item;
typedef struct Row {
    s32 unknown;
    s32 group;
    Item *item;
} Row;
typedef struct List {
    u8 pad00[0x54];
    s32 selected;
} List;

extern char D_00321BA4[];
extern u8 D_00322EA4[];
extern s32 func_004A2798(s32 *group, s32 index);
extern s32 func_00506000(s32 handle, s32 enabled);
extern const char *func_0045E850(s32 label);
extern s32 func_005062D0(s32 handle, const char *text);
extern s32 func_00506590(s32 handle, u32 value);
extern s32 func_004FD588(void);
extern void func_00498618(char *text, s32 value, s32 sign);
extern s32 func_005063C0(s32 handle, u32 color);

void func_004DB1F8(List *list, Row *row, s32 index)
{
    Item *item = row->item;
    s32 handle;
    s32 *group;
    char *text;

    func_00506000(func_004A2798(&row->group, 6), item->kind == 0);
    func_00506000(func_004A2798(&row->group, 2), item->kind != 0);
    if (item->kind == 0) {
        handle = func_004A2798(&row->group, 7);
        func_005062D0(handle, func_0045E850(item->label));
        return;
    }
    func_00506590(func_004A2798(&row->group, 4), 0x7546);
    if (func_004FD588() >= item->cost) {
        handle = func_004A2798(&row->group, 3);
        func_005062D0(handle, func_0045E850(item->label));
    } else {
        handle = func_004A2798(&row->group, 3);
        func_005062D0(handle, func_0045E850(0x16F));
    }
    if (item->cost == 0) {
        handle = func_004A2798(&row->group, 5);
        group = &row->group;
        func_005062D0(handle, func_0045E850(0x30DC));
    } else {
        text = (char *)((u32)D_00321BA4 + (u32)index * 16u);
        group = &row->group;
        func_00498618(text, item->cost, 0);
        func_005062D0(func_004A2798(group, 5), text);
    }
    if (item->enabled != 0) {
        func_005063C0(func_004A2798(group, 4), 0x80808080u);
        func_005063C0(func_004A2798(group, 3), 0x80808080u);
        if (item->cost == 0)
            func_005063C0(func_004A2798(group, 5), 0x8040D0D0u);
        else
            func_005063C0(func_004A2798(group, 5), 0x80D0D0D0u);
    } else {
        func_005063C0(func_004A2798(group, 4), 0x80404040u);
        func_005063C0(func_004A2798(group, 3), 0x80404040u);
        func_005063C0(func_004A2798(group, 5), 0x80404080u);
    }
    if (list->selected == index) {
        func_005063C0(func_004A2798(group, 4), 0x80D0D0D0u);
        func_005063C0(func_004A2798(group, 3), 0x80D0D0D0u);
    }
    if (item->label == 0x30EB && *(s32 *)(D_00322EA4 + 0x94) == 0 && func_004FD588() >= item->cost)
        func_005063C0(func_004A2798(group, 3), 0x807B00C9u);
}
