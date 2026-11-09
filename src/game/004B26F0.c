#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
} Type3096A8Entry;

typedef struct {
    s32 unk0;
    u8 pad4[0x2C];
    Type3096A8Entry unk30[3];
    u8 pad78[0x4];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0xDC];
    u8 unk160;
    u8 pad161[3];
    s32 unk164;
    u8 pad168[0xC];
    s32 unk174;
} Type3096A8;

extern s32 func_0045E038(s32);
extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_00497980(s32 arg0);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_00499CE0(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32 handle, f32 a, f32 b);
extern void func_00504550(s32, void *, f32 *);
extern s32 func_00505238(u32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00506120(u32 id, u32 value);
extern s32 D_00221748;
extern u8 D_001CE0D8[];
extern Type3096A8 D_003096A8;

u8 D_0021F7B0 = 1;
u8 D_0021F7B1 = 0;

void func_004B26F0(void) {
    f32 sp0;
    f32 sp4;
    f32 target;
    Type3096A8Entry *entry;
    s32 handle;

    if (D_003096A8.unk164 == 0) {
        D_003096A8.unk160 = 0;
        D_003096A8.unk0++;
        return;
    }
    if (D_0021F7B1 == 0) {
        D_0021F7B1 = 1;
        entry = &D_003096A8.unk30[D_003096A8.unk80];
        handle = func_004A1A60(&D_00221748, 0x3A);
        func_00505238(handle, func_0045E038(entry->unk14));
        if (D_003096A8.unk174 != 0) {
            func_00499CE0(D_003096A8.unk174);
        }
        D_003096A8.unk174 = func_00499CA0(D_001CE0D8 + entry->unk10 * 8, -1);
        func_005054F8(func_004A1A60(&D_00221748, 0x34), 1);
        func_00506120(func_004A1A60(&D_00221748, 0x34), D_003096A8.unk174);
    }
    if (D_003096A8.unk160 == 0) {
        D_003096A8.unk160 = 1;
        if (D_0021F7B0 != 0) {
            func_00497980(0x2B);
        } else {
            func_00497980(0x2D);
        }
    }
    func_00504550(func_004A1A60(&D_00221748, 0x2E), &sp0, &sp4);
    sp0 -= 0.5f;
    target = 0.75f;
    if (D_0021F7B0 != 0) {
        target = 0.0f;
    }
    if (func_004757E0(&sp0, target, 0.0f, 0.05f) != 0.0f) {
        func_00504238(func_004A1A60(&D_00221748, 0x2E), sp0 + 0.5f, sp4);
        func_00504238(func_004A1A60(&D_00221748, 0x36), 0.5f - sp0, sp4);
        return;
    }
    if (D_0021F7B0 != 0) {
        D_003096A8.unk7C = 0x78;
        D_003096A8.unk160 = 0;
        D_0021F7B0 = 0;
        func_00497980(0x2C);
        return;
    }
    if (D_003096A8.unk80 < D_003096A8.unk164 - 1) {
        D_0021F7B0 = 1;
        D_0021F7B1 = 0;
        func_00504238(func_004A1A60(&D_00221748, 0x2E), -0.25f, sp4);
        func_00504238(func_004A1A60(&D_00221748, 0x36), 1.25f, sp4);
        D_003096A8.unk160 = 0;
        D_003096A8.unk80++;
        return;
    }
    D_0021F7B0 = 1;
    D_0021F7B1 = 0;
    D_003096A8.unk80 = 0;
    D_003096A8.unk160 = 0;
    D_003096A8.unk0++;
}
