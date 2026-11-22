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
typedef struct {
    char pad[0x40];
    Object *slots[0x6A];
    s32 n;
} Holder;
extern Manager D_00222038[];
extern u32 D_00220B50;
extern Manager *func_005010E0(void);
extern Object *func_005005E8(void *, u32);
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, D_00220B50))
        return p;
    return 0;
}
extern s32 func_0050C9A8(void *, s32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222038;
    if (p->table)
        return p;
    return func_005010E0();
}
s32 func_0050C8C8(Holder *h, u32 id)
{
    s32 result = 0;
    Manager *m = getManager();
    char *state = m->table;
    void *table = 0;
    Object *p;
    s32 i;
    s32 n;
    if (state)
        table = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    p = valid(func_005005E8(table, id));
    i = 0;
    if (p) {
        while (i < h->n) {
            if (p == *(h->slots + i)) {
                result = func_0050C9A8(h, i);
                break;
            }
            i++;
        }
    }
    return result;
}
