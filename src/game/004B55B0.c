#include "common.h"

extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004B57C0(void);
extern s32 func_00504338(u32 id, f32 value);
extern s32 func_005043F0(u32 id, f32 value);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00506120(u32 id, u32 value);
extern u8 D_00171DEB[];
extern s32 D_001CE368[];
extern s32 D_00221768;
extern s32 D_0022176C;

void func_004B55B0(void) {
    func_004B57C0();
    D_0022176C = func_00499CA0(D_001CE368, -1);
    func_005054F8(func_004A1A60(&D_00221768, 0x15), 1);
    func_00506120(func_004A1A60(&D_00221768, 0x15), D_0022176C);
    func_00504338(func_004A1A60(&D_00221768, 1), -0.5f);
    func_00504338(func_004A1A60(&D_00221768, 0xB), 1.5f);
    if (D_00171DEB[0] != 0) {
        func_005043F0(func_004A1A60(&D_00221768, 1), 0.405f);
        func_005043F0(func_004A1A60(&D_00221768, 0xB), 0.61f);
    }
}
