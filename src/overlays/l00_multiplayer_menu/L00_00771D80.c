#include "common.h"
typedef struct { unsigned int x[8]; } __attribute__((packed)) Block;
typedef struct { char pad[0x15]; char flag; char pad2[2]; Block data; } Target;
typedef struct { char pad[0x50]; Target *target; } Root;
extern Root *D_002233A4;
/* Clears a flag and copies a 32-byte record. */
void func_L00_00771D80(Block *p) {
    Target *t = D_002233A4->target;
    t->flag = 0;
    t->data = *p;
}
