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
extern s32 func_004A1A60(s32 *group, s32 index);
extern s32 func_00504F68(s32 handle, s32 enabled);
extern const char *func_0045E038(s32 label);
extern s32 func_00505238(s32 handle, const char *text);
extern s32 func_005054F8(s32 handle, u32 value);
extern s32 func_004FC518(void);
extern void func_004979A8(char *text, s32 value, s32 sign);
extern s32 func_00505328(s32 handle, u32 color);

void func_004DA2D8(List *list, Row *row, s32 index)
{
    Item *item = row->item;
    s32 handle;
    s32 *group;
    char *text;

    func_00504F68(func_004A1A60(&row->group, 6), item->kind == 0);
    func_00504F68(func_004A1A60(&row->group, 2), item->kind != 0);
    if (item->kind == 0) {
        handle = func_004A1A60(&row->group, 7);
        func_00505238(handle, func_0045E038(item->label));
        return;
    }
    func_005054F8(func_004A1A60(&row->group, 4), 0x7546);
    if (func_004FC518() >= item->cost) {
        handle = func_004A1A60(&row->group, 3);
        func_00505238(handle, func_0045E038(item->label));
    } else {
        handle = func_004A1A60(&row->group, 3);
        func_00505238(handle, func_0045E038(0x16F));
    }
    if (item->cost == 0) {
        handle = func_004A1A60(&row->group, 5);
        group = &row->group;
        func_00505238(handle, func_0045E038(0x30DC));
    } else {
        text = (char *)((u32)D_00321BA4 + (u32)index * 16u);
        group = &row->group;
        func_004979A8(text, item->cost, 0);
        func_00505238(func_004A1A60(group, 5), text);
    }
    if (item->enabled != 0) {
        func_00505328(func_004A1A60(group, 4), 0x80808080u);
        func_00505328(func_004A1A60(group, 3), 0x80808080u);
        if (item->cost == 0)
            func_00505328(func_004A1A60(group, 5), 0x8040D0D0u);
        else
            func_00505328(func_004A1A60(group, 5), 0x80D0D0D0u);
    } else {
        func_00505328(func_004A1A60(group, 4), 0x80404040u);
        func_00505328(func_004A1A60(group, 3), 0x80404040u);
        func_00505328(func_004A1A60(group, 5), 0x80404080u);
    }
    if (list->selected == index) {
        func_00505328(func_004A1A60(group, 4), 0x80D0D0D0u);
        func_00505328(func_004A1A60(group, 3), 0x80D0D0D0u);
    }
    if (item->label == 0x30EB && *(s32 *)(D_00322EA4 + 0x94) == 0 && func_004FC518() >= item->cost)
        func_00505328(func_004A1A60(group, 3), 0x807B00C9u);
}
