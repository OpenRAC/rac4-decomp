#include "pal/l00_roster_001E0DF8.h"

typedef struct List {
    u8 pad0[0x260];
    char names[10][16];
} List;

extern u8 *D_0021E070;
extern s32 func_0011AB04(char *);

static inline Roster *roster(void) {
    return &D_001E0DF8;
}

// roster compare
s32 func_L00_0073FA30(List *l, s32 a, s32 b) {
    Roster *r;
    u8 *q;
    s32 *t;
    s32 *sc;
    s16 *k;

    if (func_0011AB04(l->names[a]) == 0 && func_0011AB04(l->names[b]) == 0) {
        return 0;
    }
    if (func_0011AB04(l->names[a]) == 0) {
        return 1;
    }
    if (func_0011AB04(l->names[b]) == 0) {
        return 0;
    }
    if (D_0021E070 != NULL) {
        q = D_0021E070 + 0x104;
        if (q[a] == 0xFF) {
            return 1;
        }
        if (q[b] == 0xFF) {
            return 0;
        }
    }
    r = roster();
    if (r->x18 != 0 && r->x1C != -1) {
        t = r->team;
        if (t[a] != r->x1C) {
            if (t[b] == r->x1C) {
                return 1;
            }
        } else if (t[b] != r->x1C) {
            return 0;
        }
    }
    r = roster();
    sc = r->score;
    if (sc[a] < sc[b]) {
        return 1;
    }
    if (sc[a] == sc[b]) {
        k = r->kills;
        if (k[a] > k[b]) {
            return 1;
        }
    }
    return 0;
}
