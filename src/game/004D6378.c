#include "common.h"

extern s32 D_0031D100[];
extern s32 D_00221AD8;
extern u8 D_001CDAF0[];
extern s32 func_00505B20(void);
extern void func_00501638(s32, s32, s32);
extern void func_00505B70(s32, s32);
extern s32 func_004A1A60(const s32 *, s32);
extern const char *func_0045E038(s32);
extern s32 func_00505238(u32, const char *);
extern s32 func_00499CA0(s32, s32);
extern void func_005054F8(s32, s32);
extern void func_00506120(s32, s32);

void func_004D6378(void) {
    s32 *record = (s32 *)(func_00505B20() * 0x528 + (s32)D_0031D100);
    func_00501638((s32)&D_00221AD8, 0x29, -1);
    func_00505B70(0xF, D_00221AD8);
    func_00505238(func_004A1A60(&D_00221AD8, 0xA), func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_00221AD8, 9), func_0045E038(0x31CE));
    func_00505238(func_004A1A60(&D_00221AD8, 0xB), func_0045E038(0x2F0B));
    record[2] = func_00499CA0((s32)D_001CDAF0, -1);
    func_005054F8(func_004A1A60(&D_00221AD8, 4), 1);
    func_00506120(func_004A1A60(&D_00221AD8, 4), record[2]);
}
