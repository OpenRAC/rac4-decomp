#include "common.h"

typedef struct { s32 id; s32 time; } Type1;
typedef struct { u8 pad[0x218]; s32 f218; } Type2;
extern Type1 D_004AB6D0[];
extern Type2 D_00172160;

/* Expires the first of the eight entries of D_004AB6D0 with this id whose time is past the clock word at +0x218 of D_00172160 minus 2000: its id becomes -1. */
void func_L00_005846B8(s32 id) {
    Type1 *e = D_004AB6D0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (e->id == id && D_00172160.f218 - 2000 < e->time) {
            e->id = -1;
            return;
        }
        e++;
    }
}
