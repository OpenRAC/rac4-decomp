#include "common.h"

typedef struct {
    u8 pad0[0x2b4];
    s32 f2b4;
} Type2;

typedef struct {
    u8 pad0[0xac];
    Type2 *fac;
} Type1;

/* Set the field at offset 0x2b4 in the object's referenced structure. */
void func_0042F150(Type1 *p, s32 value) {
    p->fac->f2b4 = value;
}
