/* Not matching yet: BYTES 8/80 (tools/try_func.py func_0015F018 build/try/func_0015F018/p1.c --diff).
 * The only difference is the scheduling order of the `s0` save and `ra` save. */
#include "common.h"

typedef struct {
    u8 pad[0x1C0];
    s32 f1C0;
} Type1;

typedef struct {
    u8 pad[0x1C];
    Type1 *f1C;
} Type2;

Type1 *D_0021DFE8 = 0;
extern s32 func_01EC94C0(void **);

void func_0015F018(s32 arg0, s32 arg1) {
    Type2 *object = NULL;

    if (func_01EC94C0((void **)&object) == 0 && D_0021DFE8 == NULL) {
        D_0021DFE8 = object->f1C;
        D_0021DFE8->f1C0 = arg1;
    }
}
