#include "common.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
typedef struct { u8 pad[24]; s32 value[4][4]; u8 tail[12]; } Group;
extern Entry D_003D92A0[];
extern Group D_003092A0[];
s32 D_0021F738 = 0;
s32 D_0021F73C = 0;
void func_004AE190(void) {
    Entry *p;
    s32 i, j;
    p = D_003D92A0;
    do {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p++;
    } while ((s32)p < (s32)(D_003D92A0 + 4));
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_003092A0[i].value[0][j] = 0;
            D_003092A0[i].value[1][j] = 0;
            D_003092A0[i].value[2][j] = 0;
            D_003092A0[i].value[3][j] = 0;
        }
    }
    D_0021F738 = 0;
    D_0021F73C = 2;
}
