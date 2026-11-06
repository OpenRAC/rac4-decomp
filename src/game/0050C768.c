#include "common.h"
typedef struct {
    u8 prefix[0x1E8];
    s32 count;
} Container;
extern s32 func_005015C8(void *);
void func_0050C768(Container *container)
{
    s32 i;
    for (i = 0; i < container->count; i++) {
        void **entry = (void **)((u32)container + 0x40 + (u32)i * 4);
        if (*entry)
            func_005015C8(*entry);
        *entry = 0;
    }
}
