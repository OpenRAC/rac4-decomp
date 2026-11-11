#include "common.h"

extern void func_00126E20(s32);
extern void func_00446E90(void);
extern void func_004472E0(s32);
extern void func_00447BA8(void);
extern s32 func_00448A68(s32);
extern void func_00448C68(s32);
extern void func_00448D98(void);
extern void func_00449448(s32 *);
extern void func_0044CFE8(void *);
extern void func_0044D150(void *);
extern void func_0046CBD8(void);
extern void func_0046D3A0();
extern void func_00490C50(void);
extern void func_004E2E30(void);
extern void func_004E2ED0(void);
extern void func_004E4000(void *);
extern void func_004E7450(u8 *);
extern void func_004E7830(s32 mask);
extern void func_004E7990(s32 reg, u64 value, s32 retained_mode);
extern void func_004E7BE8(void);
extern void func_004E7C48(void);
extern void func_004E8298(u32 x);
extern void func_004F3B18(void);
extern void func_004F9B18(void);
extern void func_004FA8D0(void);
extern void func_004FAAA8(void);
extern void func_004FAFE8(void);
extern void func_004FB860(void);
extern void func_004FB940(void);
extern void func_004FE4A0(void);
extern void func_004FE4D8(void);

extern u8 D_00100AE0[];
u32 D_00220954 = 0;
extern s32 D_002209B8;
extern s32 D_002209D8;
extern s32 D_00221210;
extern s32 D_00221218;
extern s32 D_0022121C;
extern s32 D_00221244;
extern s32 D_00221248;
extern s32 D_002212F8;
extern u8 D_00239540[];
extern u8 D_00324480[];

void func_004F3898(void) {
    D_00221244 = 0;
    D_00221248 = func_00448A68(0);
    D_002209B8 = 0;
    func_00447BA8();
    func_00446E90();
    if (D_00220954 & 1) {
        func_004F3B18();
    }
    if (D_00220954 & 2) {
        func_004E2ED0();
        func_004E8298(0x02010000);
    }
    if (D_00221210 != 0) {
        func_004E7C48();
        func_00448C68(1);
        func_00449448(&D_00221210);
        func_00448D98();
        func_004E7BE8();
    }
    if (D_00220954 & 0xC) {
        func_0046D3A0();
        func_004E8298(0x02080000);
    }
    func_00448C68(1);
    if (D_00221218 != 0) {
        func_00449448(&D_00221218);
    }
    func_004E7C48();
    func_004E7990(8, 5, 0);
    func_004E7990(0x47, 0x53001, 0);
    func_00126E20(0);
    func_00490C50();
    D_002212F8 = 9;
    func_004E7990(0x47, 0x5360B, 0);
    func_004E7450(D_00100AE0);
    func_00126E20(0);
    if (D_00220954 & 2) {
        func_004E7830(2);
        func_004FE4A0();
        func_004E4000(D_00324480);
        func_004FE4D8();
        func_004E2E30();
    }
    if (D_00220954 & 0xC) {
        func_004E7830(0x10);
        func_0046CBD8();
    }
    func_00448D98();
    if (D_0022121C != 0) {
        func_0044CFE8(D_00239540);
        func_00448C68(1);
        func_00449448(&D_0022121C);
        func_00448D98();
        func_0044D150(D_00239540);
    }
    func_004472E0(0);
    func_004F9B18();
    func_004FB860();
    if (D_002209B8 != 0) {
        func_004FA8D0();
        func_004FAAA8();
    }
    if (D_002209D8 != 0) {
        func_004FAFE8();
        D_002209D8 = 0;
    }
    func_004FB940();
}
