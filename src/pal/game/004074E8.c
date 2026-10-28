#include "common.h"

typedef struct {
    u8 pad0[0x28];
    s32 f28;
} Type1;

/* Set the object's field at offset 0x28 to one. */
void func_004074E8(Type1 *p) {
    p->f28 = 1;
}
