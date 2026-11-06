#include "common.h"

extern s32 D_002218B8;
extern s32 D_002218B0;
extern s32 D_001CDB20;
extern s32 func_00506BB8(void);
extern void func_004BA598(void);
extern void func_004BA330(void);
extern s32 func_0049A9D8(s32, s32);
extern s32 func_004A2798(const s32 *, s32);
extern void func_00506590(s32, s32);
extern void func_005071B8(s32, s32);
extern void func_0049E040(s32, s32, s32);
extern void func_0049DEA8(s32, s32, s32);
extern void func_0049DFB8(s32, s32);
extern void func_0049CFC8(s32, s32);

void func_004BA130(void) {
    s32 index = func_00506BB8();
    s32 *record = (s32 *)((index << 4) + (s32)&D_002218B8);
    func_004BA598();
    func_004BA330();
    record[0] = 1;
    record[3] = func_0049A9D8((s32)&D_001CDB20, -1);
    func_00506590(func_004A2798(&D_002218B0, 1), 1);
    func_005071B8(func_004A2798(&D_002218B0, 1), record[3]);
    func_0049E040(index, 0, D_002218B0);
    func_0049DEA8(index, 0, func_004A2798(&D_002218B0, 1));
    func_0049DFB8(index, 1);
    func_0049CFC8(index, 0);
}
