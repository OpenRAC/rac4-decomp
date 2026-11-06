#include "common.h"
typedef struct {
    u8 prefix[0x1E8];
    s32 count;
} Container;
extern s32 func_00502638(void *);
void func_0050D800(Container *container)
{
    s32 i;
    for (i = 0; i < container->count; i++) {
        void **entry = (void **)((u32)container + 0x40 + (u32)i * 4);
        if (*entry)
            func_00502638(*entry);
        *entry = 0;
    }
}
