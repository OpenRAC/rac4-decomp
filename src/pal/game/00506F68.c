#include "common.h"
typedef struct Object Object;
typedef struct {
    char pad[0x14];
    s32 (*isType)(Object *, u32);
} VTable;
struct Object {
    char pad[8];
    VTable *vtable;
};
typedef struct {
    s32 pad;
    char *table;
} Manager;
extern Manager D_00222138[];
extern u32 D_00220BEC;
extern Manager *func_00502150(void);
extern Object *func_00501658(void *, u32);
extern s32 func_0050DB58(Object *, u32, s32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222138;
    if (p->table)
        return p;
    return func_00502150();
}
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, D_00220BEC))
        return p;
    return 0;
}
static inline Object *getTyped(u32 id)
{
    Manager *m = getManager();
    char *state = m->table;
    void *table = 0;
    if (state)
        table = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    return valid(func_00501658(table, id));
}
s32 func_00506F68(u32 id, u32 child, s32 index)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p)
        result = func_0050DB58(p, child, index);
    return result;
}
