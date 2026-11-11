#include "common.h"

typedef struct {
    u8 unknown0[12];
    u8 dirty;
    u8 unknownD[11];
} Row;

typedef s32 (*Validator)(s32);

typedef struct {
    u8 unknown0[0x34];
    Row *rows;
    u8 unknown38[12];
    Validator validate;
    u8 unknown48[8];
    s32 count;
    s32 selected;
    u32 flags;
} List;

extern void func_004A1310(List *);

void func_004A1240(List *list, s32 index)
{
    s32 maximum;

    if (list->count != 0) {
        maximum = list->count - 1;
        index = index > maximum ? maximum : index;
        index = index < 0 ? 0 : index;
        if (index != list->selected) {
            if (list->selected >= 0) {
                list->rows[list->selected].dirty = 1;
            }
            list->selected = index;
            if (index >= 0) {
                list->rows[index].dirty = 1;
            }
            list->flags |= 2;
        }
        if (list->selected >= 0 && list->validate != 0 &&
            list->validate(list->selected) == 0) {
            func_004A1310(list);
        }
    }
}
