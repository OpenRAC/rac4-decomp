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
extern void *func_00502150(void);
extern Object *func_00501658(void *, s32);
extern u32 D_00220B50;
static inline Object *resolve(s32 handle)
{
    Manager *m;
    Object *obj;
    void *world;
    if (D_00222138[0].context)
        m = D_00222138;
    else
        m = func_00502150();
    world = 0;
    if (m->context)
        world = *(void **)((u32)m->context + ((u32) * (s32 *)((char *)m->context + 0x14) << 2));
    obj = func_00501658(world, handle);
    if (obj && obj->vtable->supports(obj, D_00220B50))
        return obj;
    return 0;
}
typedef s32 (*Callback)(Object *, float *, float *);
extern char D_003364B8[];
extern void *func_00508D68(void *, u32);
/* Resolve a supported object and dispatch its registered type callback. */
s32 func_00505E00(s32 handle, float *a, float *b)
{
    s32 result = 0;
    Object *obj = resolve(handle);
    if (obj) {
        u32 type = obj->vtable->type(obj);
        Callback callback = (Callback)func_00508D68(D_003364B8, type);
        if (callback)
            result = callback(obj, a, b);
    }
    return result;
}
