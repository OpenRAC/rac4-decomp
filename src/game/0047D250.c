#include "common.h"

typedef struct {
    u8 bytes[16];
} Entry;

extern Entry D_003D8B60[];

void * func_0047D250(u32 index)
{
    if (index < 17) {
        return &D_003D8B60[index];
    }
    return NULL;
}
