#include "common.h"

typedef struct Row {
    s32 unknown;
    s32 group;
} Row;
extern s32 func_004A2798(s32 *group, s32 index);
extern s32 func_00506590(s32 handle, u32 glyph);
extern s32 func_00506000(s32 handle, s32 enabled);

void func_004C6C10(Row *row, s32 enabled, s32 count)
{
    s32 *group = &row->group;

    func_00506590(func_004A2798(group, 8), 0x7546);
    func_00506590(func_004A2798(group, 7), 0x7546);
    func_00506590(func_004A2798(group, 6), 0x7546);
    func_00506590(func_004A2798(group, 5), 0x7546);
    func_00506590(func_004A2798(group, 4), 0x7546);
    func_00506000(func_004A2798(group, 8), 0);
    func_00506000(func_004A2798(group, 7), 0);
    func_00506000(func_004A2798(group, 6), 0);
    func_00506000(func_004A2798(group, 5), 0);
    func_00506000(func_004A2798(group, 4), 0);
    if (enabled) {
        switch (count) {
        case 5:
            func_00506000(func_004A2798(&row->group, 4), 1);
        case 4:
            func_00506000(func_004A2798(&row->group, 5), 1);
        case 3:
            func_00506000(func_004A2798(&row->group, 6), 1);
        case 2:
            func_00506000(func_004A2798(&row->group, 7), 1);
        case 1:
            func_00506000(func_004A2798(&row->group, 8), 1);
        }
    }
}
