#include "common.h"
typedef struct {
    s32 pad;
    void *table;
} Manager;
extern Manager D_00222138[];
extern u32 func_00503A40(void *), func_005034B8(void *), func_005034D8(u32);
extern Manager *func_00502150(void);
extern s32 func_00501E70(Manager *, u32);
char *func_005037A8(char *data, u32 *id)
{
    char *result = 0;
    *id = 0;
    if (func_00503A40(data) == 0x40502) {
        Manager *manager;
        *id = func_005034B8(data + 0x10);
        result = data + 0x14;
        if (D_00222138[0].table)
            manager = D_00222138;
        else
            manager = func_00502150();
        func_00501E70(manager, func_005034D8(*id));
    }
    return result;
}
