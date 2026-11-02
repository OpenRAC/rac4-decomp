#include "common.h"
extern void func_00510158(void *);
typedef struct {
    char p0[0x48];
    f32 f48;
    f32 f4C;
} Type1;
/* Refreshes state then returns the two float fields through output pointers. */
void func_00510108(Type1 *a, f32 *b, f32 *c)
{
    func_00510158(a);
    *b = a->f48;
    *c = a->f4C;
}
