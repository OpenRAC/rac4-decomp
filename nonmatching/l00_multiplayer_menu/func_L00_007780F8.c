/* Not matching yet: BYTES 3/196 (tools/try_func.py func_L00_007780F8 --diff). Not part of the build. */
/* cflags:  */
#include "common.h"
extern u64 func_0012E370(void);
extern long func_0012FEB0(u64, long);
extern long func_01ED8000(void *, void *, int);
extern void func_0015B548(long);
extern long func_0015B558(void);
extern u16 D_00221880[];
extern int D_002233A4;
extern char func_0015D3F8[];
int func_L00_007780F8(u8 *a1)
{
    int result;
    int base = D_002233A4;
    int error;
    u16 x;
    struct { u16 x; char pad[20]; u16 one; u16 y; } local;
    result = 1;
    if (!a1[409]) {
        local.y = *(u16 *)(a1 + 0x1B0);
        x = D_00221880[0];
        local.x = x;
        a1[409]++;
        local.one = 1;
        *(int *)(a1 + 0x19C) = func_0012FEB0(func_0012E370(), 147456);
        func_0015B548(func_01ED8000(&local, func_0015D3F8, 0));
        if (func_0015B558()) {
            error = 82;
            *(int *)(base + 16) = error;
            if (!*(int *)(base + 20)) *(int *)(base + 20) = error;
            result = 0;
        }
    }
    return result;
}
