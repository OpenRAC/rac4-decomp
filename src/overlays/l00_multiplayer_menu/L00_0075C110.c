#include "common.h"

typedef struct {
    char names[10][16];
    u8 padA0[0x104 - 0xA0];
    u8 ids[10];
    u8 pad10E[0x174 - 0x10E];
    s32 keys[10];
} Type1;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8[4];
} Type2;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x7F9 - 0x14];
    u8 f7F9[10];
} Type3;
extern char *func_0011A9EC(char *, char *);
extern Type1 *D_0021DFE8;
extern Type3 D_172160[];
extern Type2 D_1E0C70[];

/* Ages the slot table, tags each team slot, and gives a free slot to a team that is not in the table yet */
void func_L00_0075C110(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 found;
    s32 best;
    s32 idx;

    if (D_0021DFE8 != 0) {
        for (k = 0; k < 11; k++) {
            D_1E0C70[k].f4++;
        }
        for (i = 0; i < 10; i++) {
            if (D_0021DFE8->ids[i] == 0xFF) {
                D_172160[0].f7F9[i] = 2;
            } else {
                D_172160[0].f7F9[i] = 0;
            }
            if (D_0021DFE8->ids[i] != 0xFF && D_0021DFE8->ids[i] != D_172160[0].f10) {
                found = 0;
                best = 0;
                idx = -1;
                for (j = 0; j < 11; j++) {
                    if (D_1E0C70[j].f0 == D_0021DFE8->keys[i]) {
                        D_1E0C70[j].f4 = 1;
                        found = 1;
                    }
                    if (best < D_1E0C70[j].f4) {
                        best = D_1E0C70[j].f4;
                        idx = j;
                    }
                    if (D_1E0C70[j].f0 < 0) {
                        idx = j;
                        break;
                    }
                }
                if (!found && idx >= 0) {
                    D_1E0C70[idx].f0 = D_0021DFE8->keys[i];
                    D_1E0C70[idx].f4 = 1;
                    func_0011A9EC((char *)D_1E0C70[idx].f8, D_0021DFE8->names[i]);
                }
            }
        }
    }
}
