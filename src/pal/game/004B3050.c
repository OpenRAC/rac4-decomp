#include "common.h"
typedef struct {
    int f0;
    unsigned int flags;
    char pad[0x174];
} State;
extern State D_003097A8[];
extern void func_00453E20(void *, int, unsigned int);
extern void *func_004B2FF0(void);
extern int func_00506BB8(void), func_00506D28(void *), func_00506B70(int);
extern void func_00502508(void *);
void func_004B3050(int bit)
{
    State *p = D_003097A8;
    if (!p->flags) {
        int old;
        func_00453E20(p, 0, 0x17C);
        old = func_00506BB8();
        func_00506B70(4);
        func_00502508(func_004B2FF0());
        func_00506D28(func_004B2FF0());
        func_00506B70(old);
    }
    p->flags |= 1u << bit;
}
