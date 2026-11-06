#include "common.h"

typedef struct { s32 id; u8 rest[0x10]; } Type1;
extern Type1 D_004EEE00[];

/* Index of the first 0x14-byte entry of D_004EEE00 whose id is -1 or the given id. */
s32 func_L00_0059E998(s32 id) {
    s32 i;
    for (i = 0; D_004EEE00[i].id != -1 && D_004EEE00[i].id != id; i++) {
    }
    return i;
}
