/* cflags: -O2 -G8 -fopt-stack -Wuninitialized */
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

typedef struct Manager {
    s32 f0;
    void *context;
} Manager;

typedef s32 (*Callback)(Object *, u32);

extern Manager D_00223248[];
extern void *func_00502150(void);
extern Object *func_00501658(void *, s32);
extern u32 D_00220488;
extern char D_00343E58[];
extern Callback func_L00_006A3C40(void *, u32);

static inline Object *resolve(s32 handle)
{
    Manager *manager;
    Object *object;
    void *world;

    if (D_00223248[0].context)
        manager = D_00223248;
    else
        manager = func_00502150();
    world = NULL;
    if (manager->context)
        world = *(void **)((u32)manager->context +
            ((u32)*(s32 *)((u8 *)manager->context + 0x14) << 2));
    object = func_00501658(world, handle);
    if (object && object->vtable->supports(object, D_00220488))
        return object;
    return NULL;
}

/* Resolve a supported object and invoke the callback registered for its type. */
s32 func_L00_006A0EA0(s32 handle, u32 value)
{
    s32 result = 0;
    Object *object = resolve(handle);

    if (object) {
        u32 type = object->vtable->type(object);
        Callback callback = func_L00_006A3C40(D_00343E58, type);
        if (callback)
            result = callback(object, value);
    }
    return result;
}
