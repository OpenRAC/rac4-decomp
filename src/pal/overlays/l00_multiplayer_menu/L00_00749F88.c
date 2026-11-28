#include "pal/l00_roster_001E0DF8.h"

typedef struct List {
    u8 pad0[0x260];
    char names[10][16];
    u8 pad300[0x168];
    s32 order[10];
} List;

extern char *func_0011A9EC(char *, u8 *);
extern s32 func_L00_00749E48(List *, s32, s32);

static inline Roster *roster(void) {
    return &D_001E0DF8;
}

// roster sort
void func_L00_00749F88(List *l) {
    s32 i;
    s32 j;
    s32 t;
    u8 *src;

    for (i = 0; i < 10; i++) {
        src = roster()->names[i];
        if (*src != 0) {
            func_0011A9EC(l->names[i], src);
        } else {
            l->names[i][0] = 0;
        }
        l->order[i] = i;
    }
    if (roster()->x1C != -1) {
        for (i = 0; i < 10; i++) {
            for (j = i + 1; j < 10; j++) {
                if (func_L00_00749E48(l, l->order[i], l->order[j]) != 0) {
                    t = l->order[i];
                    l->order[i] = l->order[j];
                    l->order[j] = t;
                }
            }
        }
    }
}
