#include "common.h"

typedef struct Object Object;
typedef struct {
    u8 unknown0[0x14];
    s32 (*isType)(Object *, u32);
} VTable;
struct Object {
    u8 unknown0[8];
    VTable *vtable;
};
typedef struct {
    s32 unknown0;
    char *table;
} Manager;
typedef struct {
    u8 unknown0[0x1E8];
    s32 count;
} Container;

extern Manager D_00222038[];
u32 D_00220B50 = 1;
extern Manager *func_005010E0(void);
extern Object *func_005005E8(void *, u32);
extern s32 func_0050CAC0(Container *, u32, s32);

static inline Manager *manager(void)
{
    Manager *p = D_00222038;
    if (p->table)
        return p;
    return func_005010E0();
}
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, D_00220B50))
        return p;
    return NULL;
}
static inline Object *lookup(u32 id)
{
    Manager *p = manager();
    char *state = p->table;
    void *table = NULL;
    if (state)
        table = *(void **)((u32)state + ((u32) * (s32 *)(state + 0x14) << 2));
    return valid(func_005005E8(table, id));
}

s32 func_0050C7D8(Container *container, u32 child, u32 id)
{
    s32 result = 0;
    Object *p = lookup(id);
    s32 i;
    if (p) {
        for (i = 0; i < (s32)((u32)container->count - 1); i++) {
            if (p == *(Object **)((u32)container + 0x40 + ((u32)i << 2))) {
                result = func_0050CAC0(container, child, i);
                break;
            }
        }
    }
    return result;
}
