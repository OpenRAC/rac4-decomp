#include "common.h"

typedef struct Allocator Allocator;
typedef struct {
    void *unused[3];
    void (*release)(Allocator *, void *);
} AllocatorVtable;
struct Allocator {
    AllocatorVtable *vtable;
};
typedef struct {
    void *vtable;
    void *context;
} Manager;
typedef struct {
    char pad[8];
    void *vtable;
    char padC[0x34];
    void *block;
} Object;
extern Manager D_00222138[];
extern char D_003D3768[], D_003D3548[];
extern Manager *func_00502150(void);
extern Allocator *func_00502218(Manager *, s32);
extern void func_0015DB98(void *);
static inline Manager *manager(void)
{
    Manager *p = D_00222138;
    if (p->context)
        return p;
    return func_00502150();
}
/* Releases owned storage and optionally deletes the object itself. */
void func_0050FD80(Object *p, u32 flags)
{
    Allocator *allocator;
    p->vtable = D_003D3768;
    allocator = func_00502218(manager(), 1);
    if (allocator) {
        allocator->vtable->release(allocator, p->block);
        p->block = 0;
    }
    p->vtable = D_003D3548;
    if (flags & 1)
        func_0015DB98(p);
}
