#include "common.h"
typedef struct {
    s32 pad;
    void *table;
} Manager;
extern Manager D_00222038[];
extern s32 D_0023F450[];
extern s32 D_0021EDC4;
u8 D_0021F554 = 0;
extern Manager *func_005010E0(void);
extern s32 func_005012C8(Manager *, s32);
extern void func_00501090(Manager *);
static inline Manager *manager(void)
{
    Manager *p = D_00222038;
    if (p->table)
        return p;
    return func_005010E0();
}
void func_00496A78(s32 index)
{
    if (!D_0023F450[0] && D_0021EDC4 != 3 && !D_0021F554) {
        func_005012C8(manager(), index);
        func_00501090(manager());
    }
}
