#include "common.h"

extern void func_00499CE0(s32 arg0);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern s32 D_31E898[];

// Takes the slot at index func_00505B20() (stride 0x528) of D_31E898, and if its word 2 is set, frees it and clears the word.
void func_004D7B68(void) {
    s32 *ent;
    s32 v;

    ent = (s32 *)((s8 *)D_31E898 + func_00505B20() * 0x528);
    func_00505D30(0xF);
    v = ent[2];
    if (v != 0) {
        func_00499CE0(v);
        ent[2] = 0;
    }
}
