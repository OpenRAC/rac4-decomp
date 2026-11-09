#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x11];
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 pad26[0x10];
    s16 unk36;
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Type2;

extern s32 func_0011D920(char *arg0, char *arg1, ...);
extern s32 func_0045E038(s32);
extern void func_004979A8(void *, s32, s32);
extern void func_00498C98(Type2 *arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(s32, void *);
extern void func_00505328(s32, u32);

extern Type1 D_00171B40[];
extern char D_0021FA00[];
extern s32 D_002218C8;
extern char D_0030B990[];
extern char D_0030B9A8[];
extern Type2 D_0030B9C0;

char D_002218A8[8] = {0};
char D_002218B0[8] = {0};
char D_002218B8[8] = {0};
char D_002218C0[8] = {0};

void func_004C7E90(void) {
    s32 id;

    func_004979A8(D_0030B990, D_00171B40[0].unkC, 0);
    func_004979A8(D_0030B9A8, D_00171B40[0].unk0, 0);
    func_00505238(func_004A1A60(&D_002218C8, 0x26), D_0030B990);
    func_00505238(func_004A1A60(&D_002218C8, 0x24), D_0030B9A8);
    func_00505328(func_004A1A60(&D_002218C8, 0x26), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_002218C8, 0x24), 0x80D0D0D0);
    D_0030B9C0.f0 = 5;
    D_0030B9C0.f4 = D_00171B40[0].unk36;
    func_00498C98(&D_0030B9C0);
    id = func_004A1A60(&D_002218C8, 0x2A);
    func_00505238(id, (void *)func_0045E038(D_0030B9C0.f14));
    func_00505328(func_004A1A60(&D_002218C8, 0x2A), 0x80D0D0D0);
    func_0011D920(D_002218A8, D_0021FA00, D_00171B40[0].unk23);
    func_0011D920(D_002218B0, D_0021FA00, D_00171B40[0].unk21);
    func_0011D920(D_002218B8, D_0021FA00, D_00171B40[0].unk24);
    func_0011D920(D_002218C0, D_0021FA00, D_00171B40[0].unk25);
    func_00505238(func_004A1A60(&D_002218C8, 0x18), D_002218A8);
    func_00505238(func_004A1A60(&D_002218C8, 0x19), D_002218B0);
    func_00505238(func_004A1A60(&D_002218C8, 0x1A), D_002218B8);
    func_00505238(func_004A1A60(&D_002218C8, 0x1B), D_002218C0);
    func_00505328(func_004A1A60(&D_002218C8, 0x18), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_002218C8, 0x19), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_002218C8, 0x1A), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_002218C8, 0x1B), 0x80D0D0D0);
}
