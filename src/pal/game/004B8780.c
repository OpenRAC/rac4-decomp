#include "common.h"

extern s32 D_00171250[];
extern s32 D_00171F70[][10];
typedef struct Stats {
    u8 pad0[0x78];
    s32 level[1][4];
} Stats;
extern Stats D_00171DB8;
extern s32 func_00506BB8(void);
extern u8 *func_00511CC0(s32);
extern void func_004985F0(s32);
extern void func_004B6AD0(s32);

// weapon level
void func_004B8780(void) {
    s32 i;
    s32 w;
    s32 lvl;

    i = func_00506BB8();
    w = *(s32 *)(func_00511CC0(i) + 0x2F10);
    lvl = D_00171250[w];
    if (D_00171F70[lvl][w] == 0x40) {
        D_00171F70[lvl][w] = 0;
    } else {
        D_00171F70[lvl][w] += 8;
        if (D_00171F70[lvl][w] > 0x40) {
            D_00171F70[lvl][w] = 0x40;
        }
    }
    D_00171DB8.level[lvl][i] = D_00171F70[lvl][w];
    func_004985F0(0x10);
    func_004B6AD0(i);
}
