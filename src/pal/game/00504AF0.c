#include "common.h"
typedef struct Manager Manager;
typedef struct {
    void *pad[2];
    void *(*allocate)(Manager *, s32);
} VTable;
struct Manager {
    VTable *vtable;
    void *initialized;
};
extern Manager D_00222138[];
extern Manager *func_00502150(void);
extern Manager *func_00502218(Manager *, s32);
extern void *func_0015DB90(s32, void *);
s32 *func_00504AF0(void)
{
    Manager *manager = D_00222138;
    s32 *p;
    if (!manager->initialized)
        manager = func_00502150();
    manager = func_00502218(manager, 2);
    p = manager->vtable->allocate(manager, 192);
    if (p) {
        s32 i;
        s32 *q;
        p = func_0015DB90(192, p);
        q = p + 47;
        for (i = 47; i >= 0; i--)
            *q-- = 0;
        return p;
    }
    return 0;
}
