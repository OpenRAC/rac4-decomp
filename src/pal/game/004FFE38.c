#include "common.h"
typedef struct {
    s32 unused;
    u8 *state;
} Manager;
typedef struct {
    u8 prefix[0x10];
    u32 handle;
} Object;
extern Manager D_00222138[];
extern Manager *func_00502150(void);
extern s32 func_00500980(void *, u32);
static inline Manager *manager(void)
{
    if (D_00222138->state)
        return D_00222138;
    return func_00502150();
}
s32 func_004FFE38(Object *object)
{
    u8 *state = manager()->state;
    void *table = NULL;
    if (state)
        table = *(void **)((u32)state + ((u32) * (s32 *)(state + 0x14) << 2));
    return func_00500980(table, object->handle);
}
