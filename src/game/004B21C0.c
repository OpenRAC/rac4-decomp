#include "common.h"
typedef struct {
    int f0;
    unsigned int flags;
    char pad[0x174];
} State;
extern State D_003096A8[];
extern void func_00453608(void *, int, unsigned int);
extern void *func_004B2160(void);
extern int func_00505B20(void), func_00505C90(void *), func_00505AD8(int);
extern void func_00501498(void *);
void func_004B21C0(int bit)
{
    State *p = D_003096A8;
    if (!p->flags) {
        int old;
        func_00453608(p, 0, 0x17C);
        old = func_00505B20();
        func_00505AD8(4);
        func_00501498(func_004B2160());
        func_00505C90(func_004B2160());
        func_00505AD8(old);
    }
    p->flags |= 1u << bit;
}
