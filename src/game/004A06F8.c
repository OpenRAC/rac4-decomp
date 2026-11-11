#include "common.h"

typedef struct Allocator Allocator;
typedef struct Object Object;
typedef struct {
    u32 unknown0[2];
    void *(*allocate)(Allocator *, s32);
    void (*release)(Allocator *, void *);
} AllocatorVtable;
struct Allocator {
    AllocatorVtable *vtable;
};
typedef struct Manager {
    void *unknown0;
    u8 *table;
} Manager;
typedef struct {
    u32 unknown0[2];
    void (*destroy)(Object *, s32);
} ObjectVtable;
struct Object {
    u32 unknown0[2];
    ObjectVtable *vtable;

    u8 unknownC[0x50];
};

extern Manager D_00222038[];
extern Manager *func_005010E0(void);
extern Allocator *func_005011A8(Manager *, s32);
extern void func_00504228(s32);
extern s32 func_00504230(void);
extern s32 func_004FF910(void *, u32);
extern void *func_0015DB80(u32, void *);
extern Object *func_0050D2E8(void *);
extern s32 func_005005A8(void *, Object *, u32);

static inline Manager *get_manager(void)
{
    Manager *manager = D_00222038;
    if (manager->table) {
        return manager;
    }
    return func_005010E0();
}

s32 func_004A06F8(u32 key)
{
    s32 result = 0;
    Manager *manager;
    Allocator *allocator;
    u8 *state;
    void *entry;
    s32 size;
    void *block;
    Object *object;

    manager = get_manager();
    state = (u8 *)manager->table;
    entry = state != NULL
                ? *(void **)((u32)state + ((u32) * (s32 *)(state + 0x14) << 2))
                : NULL;
    func_00504228(0x48);
    size = func_00504230();
    if (entry != NULL && func_004FF910(entry, key) == 0) {
        allocator = func_005011A8(get_manager(), 1);
        block = allocator->vtable->allocate(allocator, size);
        if (block != NULL) {
            object = func_0050D2E8(func_0015DB80(0x48, block));
            result = func_005005A8(entry, object, key) != 0;
            if (!result) {
                object->vtable->destroy(object, 2);
                allocator = func_005011A8(get_manager(), 1);
                allocator->vtable->release(allocator, block);
            }
        }
    }
    return result;
}
