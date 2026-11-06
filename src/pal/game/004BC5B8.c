#include "common.h"

typedef struct Item {
    u8 disabled;
    u8 rest1[3];
    s32 id;
} Item;
typedef struct Row {
    u8 prefix[8];
    Item *item;
    u8 rest[12];
} Row;
typedef struct List {
    u8 prefix[0x34];
    Row *rows;
    u8 rest38[0x18];
    s32 count;
    s32 selected;
    u8 rest58[0x14];
} List;
typedef struct State {
    u8 prefix[0x4C8];
    List list;
} State;
typedef struct ItemInfo {
    s32 level;
} ItemInfo;
extern State D_0030A6F0[];
extern s32 D_0021F9D0;
extern s32 D_0021F218;
extern s32 D_0021DE98;
extern s32 func_00506BB8(void);
extern s32 func_0054C0E0(s32 group);
extern s32 func_0054C070(s32 level, s32 item);
extern ItemInfo *func_0054BF00(s32 index);
extern void func_004985F0(s32 sound);
extern void func_004BC758(void);
extern const char *func_0045E850(s32 label);
extern void func_004BC720(s32 accepted);
extern void func_0049F4C8(s32 context, const char *text, void (*callback)(s32),
                          s32 buttons, s32 f4, s32 f5, s32 f6, f32 timeout);

void func_004BC5B8(void)
{
    s32 context = func_00506BB8();
    State *state = (State *)((u32)D_0030A6F0 + (u32)context * sizeof(State));
    List *list = &state->list;
    Row *row;
    Item *item;
    s32 changed;
    s32 level;
    s32 label;

    if (list->count <= 0) {
        return;
    }
    if (list->selected < 0) {
        row = 0;
    } else {
        row = (Row *)((u32)list->rows + (u32)list->selected * sizeof(Row));
    }
    item = row->item;
    if (!item->disabled) {
        {
            ItemInfo *info = func_0054BF00(func_0054C070(func_0054C0E0(D_0021F9D0), item->id));
            changed = D_0021F218 != item->id;
            level = func_0054C0E0(info->level);
        }
        if (level != D_0021DE98 % 20) {
            func_004985F0(7);
            label = 0x3056;
        } else if (changed) {
            if (D_0021F218 == -1) {
                func_004BC758();
                return;
            }
            func_004985F0(7);
            label = 0x3057;
        } else {
            func_004985F0(7);
            label = 0x305B;
        }
        func_0049F4C8(context, func_0045E850(label), func_004BC720,
                      3, 0, 0, 0, -1.0f);
    } else {
        func_004985F0(4);
    }
}
