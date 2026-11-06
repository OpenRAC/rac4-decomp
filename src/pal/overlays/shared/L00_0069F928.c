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
extern Manager D_00223248[];
extern void *func_00502150(void);
extern void *func_00501658(void *, u32);
extern u32 D_00220520;
static inline Object *resolve(s32 handle)
{
    Manager *m;
    Object *obj;
    void *world;
    if (D_00223248[0].context)
        m = D_00223248;
    else
        m = func_00502150();
    world = 0;
    if (m->context)
        world = *(void **)((u32)m->context + ((u32) * (s32 *)((char *)m->context + 20) << 2));
    obj = func_00501658(world, handle);
    if (obj && obj->vtable->supports(obj, D_00220520))
        return obj;
    return 0;
}
f32 func_L00_0069F928(s32 handle)
{
    f32 result = 255.0f;
    Object *obj = resolve(handle);
    if (obj)
        result = *(f32 *)((char *)obj + 28);
    return result;
}
