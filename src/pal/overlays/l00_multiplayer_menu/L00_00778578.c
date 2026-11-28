#include "common.h"
#include "pal/global_002234A4.h"

typedef struct {
    u8 pad00[4];
    void *f4;
    u8 pad08[8];
    void *f10;
} Type1;

extern Type1 D_003B16D0;
extern void *func_0015DB90(u32, void *);
extern void *func_L00_00778608(void *, s32);

/* Record the block range and install the menu state built from it. */
void func_L00_00778578(void *block, s32 size)
{
    D_003B16D0.f4 = block;
    D_003B16D0.f10 = (u8 *)block + size;
    D_002234A4 = func_L00_00778608(func_0015DB90(0x90, block), size);
}
