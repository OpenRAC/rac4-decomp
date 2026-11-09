/* Not matching yet: BYTES 39/384 (tools/try_func.py func_005061D8 --diff). Not part of the build. */
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
extern Manager D_00222038[];
extern u32 D_00220B68;
extern Manager *func_005010E0(void);
extern Object *func_005005E8(void *, u32);
extern void func_0050EF28(Object *, s32, s32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222038;
    if (p->table)
        return p;
    return func_005010E0();
}
static inline Object *valid(Object *p)
{
    if (p && p->vtable->isType(p, D_00220B68))
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
s32 func_005061D8(u32 id, s32 f4, s32 f20, s32 f8, s32 f10, s32 f40, s32 f80, s32 f100, u8 f200)
{
    s32 result = 0;
    Object *p = getTyped(id);
    if (p) {
        result = 1;
        func_0050EF28(p, 0x4, f4);
        func_0050EF28(p, 0x8, f8);
        func_0050EF28(p, 0x10, f10);
        func_0050EF28(p, 0x20, f20);
        func_0050EF28(p, 0x40, f40);
        func_0050EF28(p, 0x80, f80);
        func_0050EF28(p, 0x100, f100);
        func_0050EF28(p, 0x200, f200);
    }
    return result;
}
