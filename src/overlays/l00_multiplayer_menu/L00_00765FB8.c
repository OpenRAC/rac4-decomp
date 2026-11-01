#include "common.h"
typedef struct { int words[7]; } Data;
typedef struct { char pad[0x2A]; unsigned char flag; char pad2[0xE9]; Data data; } Target;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x16]; Target *target; } Global;
extern Global *D_002233A4;
/* Copies the supplied data when the global state permits it. */
void func_L00_00765FB8(Data *arg) {
    Global *g = D_002233A4;
    Target *t = g->target;
    if (!g->flag) {
        t->data = *arg;
        t->flag = 0;
    }
}
