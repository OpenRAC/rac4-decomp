#include "common.h"

typedef struct Allocator Allocator;
typedef struct Object Object;
typedef struct {
    void *pad[2];
    void *(*allocate)(Allocator *, s32);
    void (*release)(Allocator *, void *);
} AllocatorVtable;
struct Allocator {
    AllocatorVtable *vtable;
    void *initialized;
};
typedef struct {
    void *pad[2];
    void (*destroy)(Object *, s32);
} ObjectVtable;
struct Object {
    void *pad[2];
    ObjectVtable *vtable;
};

extern Allocator D_00222138[];
extern Allocator *func_00502150(void);
extern Allocator *func_00502218(Allocator *, s32);
extern void func_005052C0(s32);
extern s32 func_005052C8(void);
extern s32 func_00500980(void *, u32);
extern void *func_0015DB90(s32, void *);
extern Object *func_0050F3F8(void *);
extern s32 func_00501618(void *, Object *, u32);

static inline Allocator *get_manager(void) {
    Allocator *manager = D_00222138;
    if (manager->initialized) {
        return manager;
    }
    return func_00502150();
}

static inline void *lookup_entry(s32 *state) {
    void **slot;
    if (state != NULL) {
        slot = (void **)((u32)state + state[5] * 4);
        return *slot;
    }
    return NULL;
}

s32 func_004A1720(u32 arg) {
    s32 result = 0;
    Allocator *manager;
    s32 *state;
    void *entry;
    s32 size;
    void *block;
    Object *object;

    manager = get_manager();
    state = (s32 *)manager->initialized;
    entry = lookup_entry(state);
    func_005052C0(0x70);
    size = func_005052C8();
    if (entry != NULL && func_00500980(entry, arg) == 0) {
        manager = func_00502218(get_manager(), 1);
        block = manager->vtable->allocate(manager, size);
        if (block != NULL) {
            object = func_0050F3F8(func_0015DB90(0x70, block));
            result = func_00501618(entry, object, arg) != 0;
            if (!result) {
                object->vtable->destroy(object, 2);
                manager = func_00502218(get_manager(), 1);
                manager->vtable->release(manager, block);
            }
        }
    }
    return result;
}
