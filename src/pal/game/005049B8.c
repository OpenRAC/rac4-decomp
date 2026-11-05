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
extern Manager D_00222138[];
extern Manager *func_00502150(void);
extern Object *func_00501658(void *, s32);
extern u32 D_00220BE8;
extern void *func_00500950(void *);
extern void *func_005038B8(void *, s32);
static inline Manager *getManager(void)
{
    Manager *p = D_00222138;
    if (p->context)
        return p;
    return func_00502150();
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
    Object *obj = func_00501658(getTable(m), id);
    if (obj && obj->vtable->supports(obj, D_00220BE8))
        return obj;
    return 0;
}
s32 func_005049B8(s32 id, s32 arg1)
{
    s32 result = 0;
    void *other;
    Object *obj;
    other = func_00500950(getTable(getManager()));
    if (other != 0) {
        obj = getTyped(id);
        if (obj != 0) {
            void *status;
            if (arg1 >= 0) {
                status = func_005038B8(other, arg1);
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
