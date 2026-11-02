#include "common.h"

typedef void (*Type1)(void *);
extern void *func_005024C8(void *, Type1, Type1, Type1, Type1, void *);
extern void func_004A2B60(void *);
extern char D_003079F0[];
s32 D_002216C0 = 0;

/* Initialize the shared descriptor with its callback on first use. */
void *func_004A2AC0(void)
{
    if (!D_002216C0) {
        func_005024C8(D_003079F0, 0, 0, func_004A2B60, 0, 0);
        D_002216C0 = 1;
    }
    return D_003079F0;
}
