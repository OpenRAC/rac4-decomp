#include "common.h"

extern void func_0046F738(void);
extern void func_00499CE0(s32 arg0);
extern void func_0049B0D8(s32 arg0);
extern void func_0049C4B0(s32, s32, s32, s32);
extern void func_004CA888(void);
extern void func_004CB5F8(void);
extern void func_004D22E0(s32 arg0);
extern s32 func_004D2360(s32 arg0);

typedef struct {
    u8 pad0[0x100];
    s32 unk100;
} Type1;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
} Type2;

extern s32 D_002218F8;
extern Type1 D_0030E5C8[];
extern Type2 D_0030E9D8;

void func_004CA0E0(void) {
    s32 i;

    func_004CA888();
    if (func_004D2360(0) != 0) {
        func_004D22E0(0);
    }
    func_0049C4B0(0, 0, D_002218F8, 0);
    func_004CB5F8();
    if (D_0030E9D8.unk10 != 0) {
        func_00499CE0(D_0030E9D8.unk10);
        D_0030E9D8.unk10 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (D_0030E5C8[i].unk100 != 0) {
            func_00499CE0(D_0030E5C8[i].unk100);
            D_0030E5C8[i].unk100 = 0;
        }
    }
    if (D_0030E9D8.unk14 != 0) {
        func_00499CE0(D_0030E9D8.unk14);
        D_0030E9D8.unk14 = 0;
    }
    func_0049B0D8(0);
    func_0046F738();
}
