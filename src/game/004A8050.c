#include "common.h"
extern s32 D_0020C690[][3];
typedef struct { char pad[0x98]; s32 flags; char tail[0x1C]; } Type1;
extern Type1 D_00308108[];
void func_004A8050(s32 arg0, s32 arg1) {
    s32 i, slot = -1;
    for (i = 0; i < 3; i++) {
        if (D_0020C690[arg0][i] == arg1) return;
        if (slot == -1 && D_0020C690[arg0][i] == 0) slot = i;
    }
    if (slot != -1) {
        D_0020C690[arg0][slot] = arg1;
        D_00308108[arg0].flags |= 8;
    }
}
