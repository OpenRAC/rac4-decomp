#include "common.h"

typedef struct {
    u8 pad[0xB2];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type1;

extern Type1 *D_00222454;
extern Type1 *D_0022246C;

/* The first 0x100-byte record from D_00222454 up to D_0022246C whose halfword at +0xB2 is id, or null. */
Type1 *func_L00_00665120(s32 unused, s32 id) {
    Type1 *p;
    for (p = D_00222454; p != D_0022246C; p++) {
        if (p->fB2 == id) {
            return p;
        }
    }
    return 0;
}
