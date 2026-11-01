#include "common.h"

typedef struct {
    u8 bytes[16];
} Entry;

extern Entry D_003D8BC0[];

void * func_0047DB88(u32 index)
{
    if (index < 17) {
        return &D_003D8BC0[index];
    }
    return NULL;
}
