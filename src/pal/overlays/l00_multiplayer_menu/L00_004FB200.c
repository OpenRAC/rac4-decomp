/* cflags: -O2 -G0 -Wuninitialized */
#include "pal/l00_hash_table.h"

extern void *(*D_00498EA8)(void *, u32, u32);

void *func_L00_004FB200(void *buffer, u32 newSize, u32 oldSize)
{
    return D_00498EA8(buffer, newSize, oldSize);
}
