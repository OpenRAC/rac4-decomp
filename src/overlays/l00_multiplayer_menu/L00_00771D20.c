#include "common.h"
typedef struct { int words[9]; } Type1;
typedef struct { char pad[0x14]; char f14; char pad2[0x23]; Type1 f38; } Type2;
typedef struct { char pad[0x50]; Type2 *f50; } Type3;
extern Type3 *D_002233A4;
/* Clears the flag and copies the supplied record. */
void func_L00_00771D20(Type1 *arg0) {
    Type2 *p = D_002233A4->f50;
    p->f14 = 0;
    p->f38 = *arg0;
}
