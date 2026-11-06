#include "common.h"

typedef struct { s32 f0; s32 f4; u8 rest[0x1C4 - 8]; } Type1;
extern Type1 D_004C8BB0[];
extern s32 D_0021E738;

/* Clears D_0021E738 and resets both 0x1C4-byte entries of D_004C8BB0 (word 4 to -1, word 0 to 0). */
void func_L00_005F16A8(void) {
    Type1 *e = D_004C8BB0;
    Type1 *end = D_004C8BB0 + 2;
    D_0021E738 = 0;
    do {
        e->f4 = -1;
        e->f0 = 0;
        e++;
    } while ((s32)e < (s32)end);
}
