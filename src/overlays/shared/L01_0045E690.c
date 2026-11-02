#include "common.h"
typedef struct Object { char pad0[0x23]; unsigned char f23; char pad24[0x10]; unsigned short f34; } Object;
typedef struct Entry { Object *f0; Object *f4; char pad8[0x48]; } Entry;
typedef struct Actor { char pad0[0x22f0]; Entry entries[6]; char pad24d0[0xa20]; Object *f2ef0; } Actor;
/* Updates the primary object and each present entry object. */
void func_L01_0045E690(Actor *a) {
    int i;

    a->f2ef0->f23 = 127;
    a->f2ef0->f34 &= 0xdfff;
    for (i = 0; i < 0x1e0; i += 0x50) {
        if (((Actor *)((char *)a + i))->entries[0].f0) { ((Actor *)((char *)a + i))->entries[0].f0->f23 = 127; ((Actor *)((char *)a + i))->entries[0].f0->f34 &= 0xdfff; }
        if (((Actor *)((char *)a + i))->entries[0].f4) { ((Actor *)((char *)a + i))->entries[0].f4->f23 = 127; ((Actor *)((char *)a + i))->entries[0].f4->f34 &= 0xdfff; }

    }
}
