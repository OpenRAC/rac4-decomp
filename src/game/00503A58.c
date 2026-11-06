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
extern Manager D_00222038[];
extern Manager *func_005010E0(void);
extern Manager *func_005011A8(Manager *, s32);
extern void *func_0015DB80(s32, void *);
s32 *func_00503A58(void)
{
    Manager *manager = D_00222038;
    s32 *p;
    if (!manager->initialized)
        manager = func_005010E0();
    manager = func_005011A8(manager, 2);
    p = manager->vtable->allocate(manager, 192);
    if (p) {
        s32 i;
        s32 *q;
        p = func_0015DB80(192, p);
        q = p + 47;
        for (i = 47; i >= 0; i--)
            *q-- = 0;
        return p;
    }
    return 0;
}
