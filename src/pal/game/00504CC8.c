#include "common.h"

typedef struct Allocator Allocator;
typedef struct AllocatorMethods {
    void *reserved[3];
    void (*release)(Allocator *allocator, void *allocation);
} AllocatorMethods;
struct Allocator {
    AllocatorMethods *methods;
};
typedef struct Manager {
    void *reserved;
    u8 *state;
} Manager;

extern Manager D_00222138[];
extern Manager *func_00502150(void);
extern void *func_00502218(Manager *manager, s32 service);
extern void func_0015DB98(void *allocation);

static inline Manager *ensureManager(Manager *manager)
{
    if (manager->state)
        return manager;
    return func_00502150();
}

void func_00504CC8(void **blocks, u32 flags)
{
    s32 i;
    void **slot;
    Manager *manager;
    Allocator *allocator;

    if (blocks != 0) {
        i = 0;
        if (blocks[0] != 0) {
            slot = blocks;
            manager = D_00222138;
            do {
                Manager *current = ensureManager(manager);
                allocator = func_00502218(current, 2);
                i++;
                allocator->methods->release(allocator, *slot);
                *slot++ = 0;
                if (i >= 48)
                    break;
            } while (*slot != 0);
        }
    }
    if (flags & 1)
        func_0015DB98(blocks);
}
