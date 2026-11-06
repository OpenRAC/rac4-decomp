#include "common.h"
typedef struct Object Object;
typedef struct {
    char pad[0x38];
    u64 *first;
    u64 *second;
    char pad40[0x1C];
    Object *child;
} Data;
extern Data *func_004765F0(Object *);
extern void func_00484320(Object *, u64 *);
static inline s32 initialized(u64 *p)
{
    return *p != 0;
}
void func_004844E0(Object *p, u64 *first, u64 *second)
{
    Data *d = func_004765F0(p);
    if (d) {
        d->second = second;
        d->first = first;
        if (first && !initialized(first))
            func_00484320(p, first);
        if (d->child && d->second && !initialized(d->second))
            func_00484320(d->child, d->second);
    }
}
