#include "common.h"

typedef struct {
    s32 f0;
    s32 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type2;

typedef struct {
    u8 pad[0x1C];
    s32 f1C;
    Type2 f20[3];
} Type1;

extern void *func_00510BE8(s32 arg0);
extern s32 *D_0021DDA4;
extern Type1 D_00354630;

void func_005431C8(s32 arg0, s32 *arg1, s32 arg2) {
    s32 best = 0;
    s32 min;
    s32 i;
    s32 id;
    void *p;

    min = D_00354630.f20[0].fC;
    D_00354630.f1C++;
    if (*D_0021DDA4 < 3) {
        if (D_00354630.f1C > 3) {
            D_00354630.f1C = 3;
        }
    } else if (D_00354630.f1C > 2) {
        D_00354630.f1C = 2;
    }
    if (min > 0) {
        for (i = 0; (*D_0021DDA4 < 3) ? (i < 3) : (i < 2); i++) {
            if (D_00354630.f20[i].fC < min) {
                min = D_00354630.f20[i].fC;
                best = i;
            }
        }
    }
    id = -1;
    p = func_00510BE8(0);
    if (p != NULL) {
        id = *(s32 *)((u8 *)p + 0x2F10);
    }
    if (arg0 == id) {
        D_00354630.f20[best].f10 = 0;
        D_00354630.f20[best].fC = 180;
    } else {
        D_00354630.f20[best].f10 = 0;
        D_00354630.f20[best].fC = 120;
    }
    D_00354630.f20[best].f0 = arg0;
    D_00354630.f20[best].f4 = arg1;
    D_00354630.f20[best].f8 = arg2;
}
