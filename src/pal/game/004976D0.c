#include "common.h"
typedef struct {
    s32 pad;
    void *table;
} Manager;
extern Manager D_00222138[];
extern s32 D_0023F550[];
extern s32 D_0021EE44;
u8 D_0021F5D4 = 0;
extern Manager *func_00502150(void);
extern s32 func_00502338(Manager *, s32);
extern void func_00502100(Manager *);
static inline Manager *manager(void)
{
    Manager *p = D_00222138;
    if (p->table)
        return p;
    return func_00502150();
}
void func_004976D0(s32 index)
{
    if (!D_0023F550[0] && D_0021EE44 != 3 && !D_0021F5D4) {
        func_00502338(manager(), index);
        func_00502100(manager());
    }
}
