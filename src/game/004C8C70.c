#include "common.h"

typedef struct {
    s32 f0, f4, f8, fC, f10, f14, f18, f1C;
} Data;
typedef struct {
    s32 a, b;
    Data *data;
    char tail[12];
} Item;
typedef struct {
    char pad[0x34];
    Item *items;
    char gap[0x18];
    s32 count, index;
} List;
typedef struct {
    s32 f0;
    s32 flags;
    char pad8[0x1304];
    List list;
    char pad1364[0x28];
    s32 handle;
} State;
typedef struct {
    s32 a, b;
} Desc;
extern State D_0030D188;
extern s32 D_002218D8;
extern Desc D_001CDB50[];
extern Desc D_001CDC28[];
extern char D_0021FA18[];
extern s32 func_0045E038(s32);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_00499CE0(s32 arg0);
extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern void func_004A13A0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504F68(u32, s32), func_00505238(u32, const char *);
extern s32 func_00506120(u32 id, u32 value);

static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}

/* Refreshes the selection panel widgets for the current list entry. */
void func_004C8C70(void)
{
    f32 x, y, z, w;
    List *l = &D_0030D188.list;
    if (l->count) {
        Data *d = selected(l)->data;
        if (d->fC) {
            func_00504F68(func_004A1A60(&D_002218D8, 0x17), 1);
            func_00504F68(func_004A1A60(&D_002218D8, 0x16), 1);
            func_00505238(func_004A1A60(&D_002218D8, 0x17), (const char *)func_0045E038(d->fC));
        } else {
            func_00504F68(func_004A1A60(&D_002218D8, 0x17), 0);
            func_00504F68(func_004A1A60(&D_002218D8, 0x16), 0);
        }
        func_00505238(func_004A1A60(&D_002218D8, 0x12), (const char *)func_0045E038(d->f14));
        func_004A13A0(&D_0030D188.list, &x, &y, &z, &w);
        func_0049BFC0(0, 0, 0, x, y, z, w);
        if (D_0030D188.handle) {
            func_00499CE0(D_0030D188.handle);
            D_0030D188.handle = 0;
        }
        D_0030D188.handle = func_00499CA0(&D_001CDB50[d->f1C], -1);
        func_00506120(func_004A1A60(&D_002218D8, 4), D_0030D188.handle);
    } else {
        func_00505238(func_004A1A60(&D_002218D8, 0x12), (const char *)func_0045E038(0x2F29));
        func_00505238(func_004A1A60(&D_002218D8, 0x17), D_0021FA18);
        if (D_0030D188.handle) {
            func_00499CE0(D_0030D188.handle);
            D_0030D188.handle = 0;
        }
        D_0030D188.handle = func_00499CA0(D_001CDC28, -1);
        func_00506120(func_004A1A60(&D_002218D8, 4), D_0030D188.handle);
    }
    D_0030D188.flags &= ~2;
}
