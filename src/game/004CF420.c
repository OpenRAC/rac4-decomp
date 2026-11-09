#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
    u8 pad30[0x20];
    s32 unk50;
} Type2;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 unk14[0x960];
    Type2 unk974;
    u8 pad[0x9E0 - 0x974 - sizeof(Type2)];
} Type1;

typedef struct {
    u8 pad[0x30];
    s32 unk30;
} Type3;

extern s32 func_0045E038(s32);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_0049C290(s32 param, s32 count);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D280(s32 player, s32 count);
extern void func_004A0BE8(void *arg0, s8 arg1);
extern void func_004A0BF0(void *param_a, s32 source, s32 param_b);
extern void func_004A1140(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5);
extern void func_004A1240(void *, s32);
extern void func_004A1440(void *, void *, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004CF6C0(s32 arg0);
extern void func_004CFAD8(s32, void *, s32);
extern void func_004CFD80(void);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern s32 func_00505DD0(u32 id, s32 amount);
extern s32 func_00506120(u32 id, u32 value);
extern void func_004CF860(void);

extern s32 D_0021DE74;
extern u8 D_001CDAF0[];
extern u16 D_001F7788[];
extern s32 D_00221980;
extern Type1 D_00316D00[];
extern Type3 D_00319480[];

void func_004CF420(void) {
    s32 player;
    Type1 *p;
    s32 i;
    s32 id;
    s32 str;
    u8 *desc;
    Type2 *s;
    Type2 *q;
    s32 g;

    player = func_00505B20();
    p = &D_00316D00[player];
    func_004CFD80();
    s = &p->unk974;
    p->unk0 = 1;
    p->unk4 = 0;
    func_004A1140(s, p->unk14, 100, func_004CF860, 30, 1);
    func_00505DD0(D_00221980, s->unk2C);
    func_004A0BF0(s, func_004A1A60(&D_00221980, 9), 1);
    func_004A0BE8(s, 1);
    func_0049D170(player, 0, func_004A1A60(&D_00221980, 10));
    func_0049D280(player, 1);
    g = D_00221980;
    func_0049C400(player, 0, g, func_004A1A60(&D_00221980, 10), 0);
    func_0049C290(player, 1);
    for (i = D_0021DE74 - 1; i >= 0; i--) {
        if (D_001F7788[i] != 0x28F6 && D_001F7788[i] != 0x28F8) {
            str = func_0045E038(D_001F7788[i]);
            if (func_004CF6C0(str) == 0) {
                func_004A1440(&p->unk974, &D_00319480[i], -1);
                func_004CFAD8(str, &D_00319480[i], 0x30);
                D_00319480[i].unk30 = D_001F7788[i];
            }
        }
    }
    q = &p->unk974;
    if (q->unk50 > 0) {
        func_004A1240(q, 0);
    }
    desc = D_001CDAF0;
    p->unkC = func_00499CA0(desc, -1);
    func_005054F8(func_004A1A60(&D_00221980, 7), 1);
    func_00506120(func_004A1A60(&D_00221980, 7), p->unkC);
    p->unk10 = func_00499CA0(desc - 0x38, -1);
    func_005054F8(func_004A1A60(&D_00221980, 1), 1);
    func_00506120(func_004A1A60(&D_00221980, 1), p->unk10);
    p->unk8 = 7;
}
