#include "common.h"

typedef struct { u8 pad[0x19C]; void *next; } E1;
extern E1 D_003E5290[];
u8 D_00220A30 = 0;
s32 D_00220A34 = 0;
void *D_00220A0C = 0;
s32 D_00220A10 = 0;
s32 D_00220A14 = 0;
s32 D_00220A18 = 0;
s32 D_00220A1C = 0;
/* Initialise a free list of 128 entries. */
void func_L00_007092B0(void) {
    s32 i;
    D_00220A30 = 0;
    D_00220A34 = 0;
    for (i = 127; i >= 0; i--) D_003E5290[i].next = &D_003E5290[i + 1];
    D_00220A0C = D_003E5290;
    D_003E5290[127].next = 0;
    D_00220A10 = 0;
    D_00220A14 = 0;
    D_00220A18 = 0;
    D_00220A1C = 0;
}
