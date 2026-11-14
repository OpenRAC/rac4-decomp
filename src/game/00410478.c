/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4; void *f8; } V;
extern void *func_00403308(void *, s32, u32);
extern s32 func_00403440(void *);
void func_00410478(V *v) {
    if (v->f8 != 0) {
        func_00403308(v->f8, 0, v->f0 * 8);
        func_00403440(v->f8);
        v->f8 = 0;
    }
    v->f0 = 0;
    v->f4 = 0;
}
