#include "common.h"

typedef struct {
    s32 pad0[7];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 pad2C[8];
    u8 pad4C[3];
    u8 unk4F;
} Type004D33C0;

typedef struct {
    s32 pad0[2];
    s32 (*unk8)(void);
    s32 pad0C;
    s32 (*unk10)(void);
} Type004D33C0_Obj;

typedef struct {
    s32 pad0[5];
    s32 (*unk14)(void);
} Type004D33C0_Mgr;

extern s32 func_00157F98(void);
extern void func_00158898(s32 arg0);
extern void func_0045C6D8(s32 arg0);
extern s32 func_0045CB20(void);
extern s32 func_0045DE00(void);
extern Type004D33C0_Obj *func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern void func_00489478(void);
extern void func_0048A0C0(s32 *arg0, s32 arg1);
extern void func_0048F7E0(u8 *arg0);
extern void func_004D3030(void);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern void func_004E7520(void);

extern Type004D33C0 D_003D9BE0;
extern Type004D33C0_Mgr *D_0021F194;
extern s32 D_0021EDC4;
extern s32 D_0021DDB4;
extern u8 D_0021EE1A;
extern s32 D_002214D0;

void func_004D33C0(void) {
    Type004D33C0_Obj *obj;
    s32 busy;

    func_0045DE00();
    func_004E7520();
    D_003D9BE0.unk24 = 0;
    D_003D9BE0.unk28 = 0;
    D_003D9BE0.unk1C = 0;
    if (D_003D9BE0.unk4F == 0) {
        D_003D9BE0.unk20 = 0;
    }
    busy = 0;
    obj = func_0046D428(0x208A, 0, 0x14);
    if (obj != 0 && obj->unk10 != 0 && obj->unk8 != 0 && obj->unk8() != 0) {
        busy = obj->unk10();
    }
    if (D_0021F194->unk14() == 0 && func_0045CB20() == 0 && busy == 0 &&
        D_0021EDC4 != 5 && D_0021DDB4 != 5) {
        func_00158898(0xCD);
        func_0048A0C0(&D_002214D0, 1);
        func_00489478();
    }
    func_00157F98();
    func_004E0858();
    func_0048F7E0(0);
    D_0021EE1A = 0;
    func_0045C6D8(0);
    if (D_0021EDC4 == 0) {
        func_004E21D8(0xFFFFFFFF, 0, 0);
    }
    func_004D3030();
}
