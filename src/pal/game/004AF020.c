#include "common.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
#include "pal/record_003093A0.h"
extern Entry D_003D9318[];
s32 D_0021F7D8 = 0;
s32 D_0021F7DC = 0;
void func_004AF020(void) {
    Entry *p;
    s32 i, j;
    p = D_003D9318;
    do {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p++;
    } while ((s32)p < (s32)(D_003D9318 + 4));
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_003093A0[i].value[0][j] = 0;
            D_003093A0[i].value[1][j] = 0;
            D_003093A0[i].value[2][j] = 0;
            D_003093A0[i].value[3][j] = 0;
        }
    }
    D_0021F7D8 = 0;
    D_0021F7DC = 2;
}
