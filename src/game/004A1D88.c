#include "common.h"

typedef void (*Type1)(void *);
extern void *func_00501458(void *, Type1, Type1, Type1, Type1, void *);
extern void func_004A1E28(void *);
extern char D_003078F0[];
s32 D_002215C0 = 0;

/* Initialize the shared descriptor with its callback on first use. */
void *func_004A1D88(void)
{
    if (!D_002215C0) {
        func_00501458(D_003078F0, 0, 0, func_004A1E28, 0, 0);
        D_002215C0 = 1;
    }
    return D_003078F0;
}
