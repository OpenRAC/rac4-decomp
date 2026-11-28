#include "common.h"
#include "pal/menu_flow.h"

/* PAL reconstruction adapted from the retained 004B41F8 attempt. */
typedef struct {
    s32 first, second;
} EntryLabels;

extern EntryLabels D_003D1CB8[];
extern s32 D_00221848;
extern const char *func_0045E850(s32 id);
extern s32 func_004A2798(s32 *group, s32 id);
extern s32 func_00506000(s32 handle, s32 enabled);
extern s32 func_005062D0(u32 handle, const char *text);
extern s32 func_005063C0(s32 handle, u32 value);

void func_004B50C0(s32 arg0, void (*arg1)(PalMenuFlowEntry *), s32 arg2, s32 arg3)
{
    s32 n = D_003097A8.entryCount;
    PalMenuFlowEntry *entry;
    s32 *second;
    s32 *first;
    s32 handle;

    D_003097A8.entryCount = n + 1;
    first = &D_003D1CB8[n].first;
    second = &D_003D1CB8[n].second;
    entry = &D_003097A8.entries[n];
    entry->f4 = arg0;
    entry->callback = arg1;
    entry->f20 = arg2;
    entry->f0 = 0;
    entry->name[0] = 0;
    func_00506000(func_004A2798(&D_00221848, *second), 1);
    func_00506000(func_004A2798(&D_00221848, *first), 1);
    handle = func_004A2798(&D_00221848, *first);
    func_005062D0(handle, func_0045E850(arg3));
    func_005062D0(func_004A2798(&D_00221848, *second), D_003097A8.entries[n].name);
    func_005063C0(func_004A2798(&D_00221848, *second), 0x80404040U);
    if (entry->callback != NULL)
        entry->callback(entry);
}
