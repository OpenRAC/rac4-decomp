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
extern Manager D_00222038[];
extern u32 D_00220AB8;
extern Manager *func_005010E0(void);
extern Object *func_005005E8(void *, u32);
typedef s32 (*Callback)(Object *, s32);
extern Callback func_00507B00(void *, u32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222038;
    if (p->table)
        return p;
    return func_005010E0();
}
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, D_00220AB8))
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
    return valid(func_005005E8(table, id));
}
extern char D_00336308[];
static inline Callback handler(u32 kind)
{
    return func_00507B00(D_00336308, kind);
}
s32 func_005054F8(u32 id, s32 amount)
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
