#include "common.h"
typedef struct { char pad[0x85c]; s32 count; char pad2[0x10a60-0x860]; s32 a; char pad3[0x10e70-0x10a64]; s32 b, c; } Type1;
static inline s32 plus(s32 a, s32 b) { return a + b; }
/* Clamp the stored range against the current count and range length. */
void func_L00_00713E00(Type1 *p) {
    if (p->count - 1 < p->a) p->a = p->count - 1;
    if (p->count - p->b < p->c) p->c = p->count - p->b;
    if (p->c > p->a) p->c = p->a;
    if (p->c < plus(p->a, 1) - p->b) p->c = plus(p->a, 1) - p->b;
    if (p->c < 0) p->c = 0;
}
