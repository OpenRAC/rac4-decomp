#include "common.h"

extern u8 D_001719C8[];
extern s32 D_0021DAC0;
extern u8 D_001FB5B8[];
extern u8 D_003D8100[];
extern s32 func_00138290(void *);
extern void func_00155A98(void *);
extern s32 func_00469508(void *, s32, void *);

static inline u8 *card(void) {
    return D_001719C8;
}

// card check
s32 func_004699A8(void) {
    u8 *mc;

    func_00138290(&D_0021DAC0);
    func_00155A98(&D_0021DAC0);
    mc = card();
    if (*(s32 *)(mc + 0x1B0) == -1) {
        return 0;
    }
    if (*(s32 *)(mc + 0x1E4) != 0 && *(s32 *)(mc + 0x1C4) < 3 && *(s32 *)(mc + 0x1CC) < 0) {
        *(u8 **)(mc + 0x1DC) = D_001FB5B8;
        func_00469508(D_001FB5B8, 0, D_003D8100);
        if (*(s32 *)(mc + 0x1CC) < 0) {
            *(s32 *)(mc + 0x1CC) = 0x22;
            *(s32 *)(mc + 0x1D0) = *(s32 *)(mc + 0x1B0);
        }
    }
    return *(s32 *)(card() + 0x1CC) == 0x22;
}
