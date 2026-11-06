#include "common.h"
typedef struct Object Object;
typedef struct Vtable {
    void *unused[3];
    u32 (*type)(Object *);
    void *f10;
    s32 (*supports)(Object *, u32);
} Vtable;
struct Object {
    s32 f0, f4;
    Vtable *vtable;
};
typedef struct {
    s32 f0;
    void *context;
} Manager;
extern Manager D_00222038[];
extern Manager *func_005010E0(void);
extern Object *func_005005E8(void *, s32);
extern u32 D_00220B50;
extern void *func_004FF8E0(void *);
extern void *func_00502848(void *, s32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222038;
    if (p->context)
        return p;
    return func_005010E0();
}
static inline void *getTable(Manager *m)
{
    void *table = 0;
    char *state = m->context;
    if (state)
        table = *(void **)(state + (*(s32 *)(state + 0x14) << 2));
    return table;
}
static inline Object *getTyped(s32 id)
{
    Manager *m = getManager();
    Object *obj = func_005005E8(getTable(m), id);
    if (obj && obj->vtable->supports(obj, D_00220B50))
        return obj;
    return 0;
}
s32 func_00503920(s32 id, s32 arg1)
{
    s32 result = 0;
    void *other;
    Object *obj;
    other = func_004FF8E0(getTable(getManager()));
    if (other != 0) {
        obj = getTyped(id);
        if (obj != 0) {
            void *status;
            if (arg1 >= 0) {
                status = func_00502848(other, arg1);
            } else {
                status = 0;
            }
            if (status != 0 || arg1 == -1) {
                *(s32 *)((u8 *)obj + 0x38) = arg1;
                result = 1;
            }
        }
    }
    return result;
}
