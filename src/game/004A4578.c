#include "common.h"

typedef struct {
    u8 pad[0xE4];
    s32 fE4;
    s32 fE8;
} Type1;
extern void func_0049A6B0(s32 arg0, s32 arg1);
extern void func_0049DFF8(s32 player, s32 index);
extern s32 func_00505B20(void);
extern s32 func_00505D30(s32 arg0);
extern Type1 D_307B58[];

/* Clear the pending pair for the current slot, then run the slot's reset call. */
void func_004A4578(void) {
    s32 id = func_00505B20();

    if (D_307B58[id].fE4 != 0 || D_307B58[id].fE8 != 0) {
        D_307B58[id].fE4 = 0;
        D_307B58[id].fE8 = 0;
        func_0049DFF8(id, 0);
    }
    func_00505D30(0x16);
    func_0049A6B0(func_00505B20(), 0x20);
}
