/* cflags:  */
#include "common.h"
extern u64 func_0012E370(void);
extern long func_0012FEB0(u64, long);
extern long func_01ED7F10(void *, void *, int);
extern void func_0015B548(long);
extern long func_0015B558(void);
extern u16 D_00221880[];
extern int D_002233A4;
extern char D_0015D3D0[];
int func_L00_00777C50(int *a1)
{
    int result = 1;
    int base = D_002233A4;
    int error;
    u16 x;
    int value = *a1;
    struct { u16 x; char pad[22]; int value; } local;
    if (value >= 0) {
        if (!*((u8 *)a1 + 349)) {
            local.value = value;
            x = D_00221880[0];
            *((u8 *)a1 + 349) = result;
            local.x = x;
            a1[88] = func_0012FEB0(func_0012E370(), 147456);
            func_0015B548(func_01ED7F10(&local, D_0015D3D0, 0));
            if (func_0015B558()) {
                error = 78;
                goto fail;
            }
        }
    } else {
        error = 79;
fail:
        *(int *)(base + 16) = error;
        if (!*(int *)(base + 20)) *(int *)(base + 20) = error;
        result = 0;
    }
    return result;
}
