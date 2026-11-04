#include "common.h"
typedef struct Object Object;
typedef struct {
    char pad[0xC];
    u32 (*getType)(Object *);
    s32 pad10;
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
extern u32 D_00220B50;
extern Manager *func_00502150(void);
extern Object *func_00501658(void *, u32);
typedef s32 (*Callback)(Object *, f32);
extern Callback func_00508C08(void *, u32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222138;
    if (p->table)
        return p;
    return func_00502150();
}
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, D_00220B50))
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
extern char D_00336738[];
static inline Callback handler(u32 kind)
{
    return func_00508C08(D_00336738, kind);
}
s32 func_00506A70(u32 id, f32 amount)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p) {
        Callback callback = handler(p->vtable->getType(p));
        if (callback)
            result = callback(p, amount);
    }
    return result;
}
