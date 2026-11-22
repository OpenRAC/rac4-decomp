#include "common.h"

extern char *func_0011A9EC(char *, char *);
extern s32 D_0022318C;
extern s32 D_00223190;
extern s32 D_00223194;
extern s32 D_00223198;
extern char D_0036D330[];
extern char D_0036D3B0[];

void func_L00_006FF348(void) {
    if (D_0022318C <= 0) {
        if (D_00223190 != 0) {
            D_0022318C = D_00223190;
            D_00223194 = D_00223198;
            func_0011A9EC(D_0036D330, D_0036D3B0);
            D_0036D3B0[0] = 0;
            D_00223198 = -1;
            D_00223190 = 0;
        }
    }
}
