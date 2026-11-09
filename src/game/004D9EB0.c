#include "common.h"

extern s32 func_00499CA0(void *, s32);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D280(s32, s32);
extern s32 func_004A0BE8(void *arg0, s8 arg1);
extern void func_004A0BF0(s32 param_a, s32 source, s64 param_b);
extern void func_004A1140(void *, void *, s32, void *, s32, s32);
extern void func_004A11F0(void *, void *);
extern s32 func_004A1A60(void *, s32);
extern void func_004DAEB8(void);
extern void func_005054F8(s32, u16);
extern void func_00505DD0(s32, s32);
extern s32 func_00506120(s32, s32);
extern void func_004DA2D8(void);
extern void func_004DACC0(void);
extern s32 D_00171B40[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern char D_001CDAC0[];
extern s32 D_00221B78;
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0xD0C - 0x8];
    u8 unkD0C[0x130C - 0xD0C];
    s32 unk130C[0x6C / 4];
    u8 unk1378;
    u8 unk1379;
    u8 pad137A[0x1388 - 0x137A];
    s32 unk1388;
    s32 unk138C;
    s32 unk1390;
    s32 unk1394;
    s32 unk1398;
    s32 unk139C;
    s32 unk13A0;
    u8 unk13A4;
    u8 unk13A5;
    u8 pad13A6[0x13B4 - 0x13A6];
    s32 unk13B4;
    s32 unk13B8;
    u8 unk13BC;
    u8 pad13BD[0x13E4 - 0x13BD];
} Type1;

extern Type1 D_00321B98;

void func_004D9EB0(void) {
    s32 *p;
    s32 key;
    s16 *cfg = (s16 *)D_00171B40;

    D_00321B98.unk0 = 0;
    D_00321B98.unk13A5 = 1;
    D_00321B98.unk13B4 = cfg[0x12 / 2];
    D_00321B98.unk13A0 = 0;
    D_00321B98.unk13BC = 0;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        D_00321B98.unk13B8 = cfg[0x34 / 2];
    }
    func_004DAEB8();
    p = D_00321B98.unk130C;
    func_004A1140(p, D_00321B98.unkD0C, 0x40, func_004DA2D8, 0x2E, 1);
    func_004A11F0(p, func_004DACC0);
    func_004A0BF0((s32)p, func_004A1A60(&D_00221B78, 0xF), 0);
    func_004A0BE8(p, 1);
    func_00505DD0(D_00221B78, p[0x2C / 4]);
    func_0049D170(0, 0, func_004A1A60(&D_00221B78, 0x10));
    func_0049D280(0, 1);
    key = D_00221B78;
    func_0049C400(0, 0, key, func_004A1A60(&D_00221B78, 0x10), 0);
    D_00321B98.unk1378 = 0x30;
    D_00321B98.unk1388 = 0;
    D_00321B98.unk1379 = 0;
    D_00321B98.unk138C = func_00499CA0(D_001CDAC0, -1);
    func_005054F8(func_004A1A60(&D_00221B78, 2), 1);
    func_00506120(func_004A1A60(&D_00221B78, 2), D_00321B98.unk138C);
    D_00321B98.unk1390 = func_00499CA0(D_001CDAC0 - 8, -1);
    func_005054F8(func_004A1A60(&D_00221B78, 1), 1);
    func_00506120(func_004A1A60(&D_00221B78, 1), D_00321B98.unk1390);
    D_00321B98.unk1394 = func_00499CA0(D_001CDAC0 + 0x3E8, -1);
    func_005054F8(func_004A1A60(&D_00221B78, 9), 1);
    func_00506120(func_004A1A60(&D_00221B78, 9), D_00321B98.unk1394);
    D_00321B98.unk139C = func_00499CA0(D_001CDAC0 + 0x70, -1);
    func_005054F8(func_004A1A60(&D_00221B78, 0xA), 1);
    func_00506120(func_004A1A60(&D_00221B78, 0xA), D_00321B98.unk139C);
    D_00321B98.unk4 = 7;
}
