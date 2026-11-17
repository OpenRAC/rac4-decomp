#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } E12;
extern E12 D_31FF90[];

// Selection-sorts the twelve 12-byte entries by their middle word, returning the last index that was moved.
s32 func_004D8058(void) {
    E12 best;
    E12 tmp;
    s32 t1;
    s32 a1;
    s32 a2;
    s32 a3;

    t1 = 0xC;
    for (a3 = 0; a3 < 0xC; a3++) {
        a2 = a3;
        best = D_31FF90[a3];
        for (a1 = a3; a1 < 0xD; a1++) {
            if (D_31FF90[a1].f4 > best.f4) {
                best = D_31FF90[a1];
                a2 = a1;
            }
        }
        if (a3 != a2) {
            tmp = D_31FF90[a3];
            D_31FF90[a3] = D_31FF90[a2];
            D_31FF90[a2] = tmp;
        }
        if (a2 == t1) {
            t1 = a3;
        }
    }
    return t1;
}
