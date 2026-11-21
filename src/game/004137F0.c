/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 sz; void (*fn)(void *); } E;
typedef struct { s32 n; s32 f4; E *e; } T;
extern void func_00403308(void *, s32, s32);
extern void func_00403440(void *);
void func_004137F0(T *t, s32 clear) {
    s32 n = t->n;
    s32 k;
    E *e = t->e;
    while (k = n, n--, k != 0) {
        if (e->p != 0) {
            if (e->fn != 0) {
                e->fn(e->p);
            } else {
                if (clear != 0) {
                    func_00403308(e->p, 0, e->sz);
                }
                func_00403440(e->p);
            }
            e->p = 0;
        }
        e++;
    }
    t->n = 0;
}
