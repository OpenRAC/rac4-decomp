/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { u16 a; u16 b; } Type1;
typedef struct { s32 n; s32 f4; u32 tab; } Type2;
extern void func_01EACB10(Type2 *);
void func_01EACB98(s32 idx, Type2 *p) {
    Type1 *e = (Type1 *)(idx * 4 + p->tab);
    if (e->a != 0xFFFF) {
        e->b = 0;
        e->a = 0xFFFF;
        if (--p->n == 0) {
            func_01EACB10(p);
        }
    }
}
