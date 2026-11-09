#include "common.h"

typedef struct {
    u8 f0[0x100];
    s32 f100;
    s32 f104;
    u8 f108[8];
} Type1;

extern s32 func_0046B5B8(void **, void *, Type1 *);
extern void *func_00510BE8(s32 arg0);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern Type1 D_00242080[];

/* Looks up an entry via func_0046B5B8, falling back to the per-slot table at D_00242080. */
void *func_0046B4E0(u8 *arg0) {
    void *out;
    void *h;
    Type1 *e;

    h = 0;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        h = func_00510BE8(*(s32 *)(arg0 + 0x2F10) == 0);
    }
    if (h != 0 && func_0046B5B8(&out, h, 0) != 0) {
        return out;
    }
    if (func_0046B5B8(&out, h, &D_00242080[*(s32 *)(arg0 + 0x2F10)]) != 0) {
        return out;
    }
    e = &D_00242080[*(s32 *)(arg0 + 0x2F10)];
    if (e->f104 > 0) {
        return e->f0 + (e->f100 << 5);
    }
    return 0;
}
