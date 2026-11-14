#include "common.h"

typedef struct { s32 f0, f4; u32 f8; } E;
extern E D_001F1400[];
void func_0045DEF0(void) {
    s32 i;
    for (i = 0; i < 0x827; i++) {
        D_001F1400[i].f8 &= 0x7FFFFFFF;
    }
}
