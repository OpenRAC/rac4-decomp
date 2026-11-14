#include "common.h"
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } Type1;
extern Type1 D_0036E050[16];
void func_L41_00629E68(void) {
    Type1 *p;
    s32 clearValue;
    s32 kind;
    s32 count;
    p = D_0036E050;
    clearValue = -1;
    kind = 10;
    count = 15;
    do {
        p->f0 = clearValue;
        count -= 1;
        p->f4 = 0;
        p->f8 = 0;
        p->fC = kind;
        p += 1;
    } while (count >= 0);
}
