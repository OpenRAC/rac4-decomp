#include "common.h"
typedef struct { char bytes[32]; } Block;
typedef struct { char pad[0xc0]; unsigned char fC0; char pad2[3]; Block fC4; } Type1;
typedef struct { char pad[0x60]; Type1 *f60; } Type2;
extern Type2 *D_002233A4;
/* Clears a flag and copies the 32-byte payload. */
void func_L00_00777750(Block *arg0) {
    Type1 *p = D_002233A4->f60;
    p->fC0 = 0;
    p->fC4 = *arg0;
}
