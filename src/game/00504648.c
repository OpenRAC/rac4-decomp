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
extern u32 D_00220AB8;
static inline Object *resolve(s32 handle)
{
    Manager *m;
    Object *obj;
    void *world;
    if (D_00222038[0].context)
        m = D_00222038;
    else
        m = func_005010E0();
    world = 0;
    if (m->context)
        world = *(void **)((u32)m->context + ((u32) * (s32 *)((char *)m->context + 0x14) << 2));
    obj = func_005005E8(world, handle);
    if (obj && obj->vtable->supports(obj, D_00220AB8))
        return obj;
    return 0;
}
typedef s32 (*Callback)(Object *, float *, float *);
extern char D_00336038[];
extern Callback func_00507A10(void *, u32);
s32 func_00504648(s32 handle, float *a, float *b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->type(obj);
        Callback callback = func_00507A10(D_00336038, type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
