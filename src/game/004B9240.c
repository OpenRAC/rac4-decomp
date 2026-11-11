#include "common.h"

extern s32 D_002217B8;
extern s32 D_002217B0;
extern s32 D_001CDAA0;
extern s32 func_00505B20(void);
extern void func_004B96A8(void);
extern void func_004B9440(void);
extern s32 func_00499CA0(s32, s32);
extern s32 func_004A1A60(const s32 *, s32);
extern void func_005054F8(s32, s32);
extern void func_00506120(s32, s32);
extern void func_0049D308(s32, s32, s32);
extern void func_0049D170(s32, s32, s32);
extern void func_0049D280(s32, s32);
extern void func_0049C290(s32, s32);

void func_004B9240(void) {
    s32 index = func_00505B20();
    s32 *record = (s32 *)((index << 4) + (s32)&D_002217B8);
    func_004B96A8();
    func_004B9440();
    record[0] = 1;
    record[3] = func_00499CA0((s32)&D_001CDAA0, -1);
    func_005054F8(func_004A1A60(&D_002217B0, 1), 1);
    func_00506120(func_004A1A60(&D_002217B0, 1), record[3]);
    func_0049D308(index, 0, D_002217B0);
    func_0049D170(index, 0, func_004A1A60(&D_002217B0, 1));
    func_0049D280(index, 1);
    func_0049C290(index, 0);
}
