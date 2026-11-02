#include "common.h"
typedef struct { u8 bytes[32]; } Block;
typedef struct { u8 pad[0x29]; u8 f29; u8 pad2[6]; Block f30; } Target;
typedef struct { u8 pad[0x1d]; u8 f1d; u8 pad2[0x16]; Target *f34; } Global;
extern Global *D_002233A4;
/* Copy the supplied block when enabled. */
void func_L00_00765F58(Block *arg) {
    Global *g = D_002233A4;
    Target *t = g->f34;
    if (g->f1d == 0) {
        t->f30 = *arg;
        t->f29 = 0;
    }
}
