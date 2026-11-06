#include "common.h"
typedef struct {
    s32 pad;
    void *table;
} Manager;
extern Manager D_00222038[];
extern u32 func_005029D0(void *), func_00502448(void *), func_00502468(u32);
extern Manager *func_005010E0(void);
extern s32 func_00500E00(Manager *, u32);
char *func_00502738(char *data, u32 *id)
{
    char *result = 0;
    *id = 0;
    if (func_005029D0(data) == 0x40502) {
        Manager *manager;
        *id = func_00502448(data + 0x10);
        result = data + 0x14;
        if (D_00222038[0].table)
            manager = D_00222038;
        else
            manager = func_005010E0();
        func_00500E00(manager, func_00502468(*id));
    }
    return result;
}
