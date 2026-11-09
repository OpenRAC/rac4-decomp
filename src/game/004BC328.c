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

extern s32 func_0011D920(char *arg0, char *arg1, ...);
extern s32 func_0045E038(s32);
extern void func_004979A8(void *, s32, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void *func_004FBF90(s32, s32);
extern s32 func_00505238(s32, void *);
extern void func_00505328(s32, u32);

extern Type1 D_00171B40[];
extern char D_0021F918[];
extern s32 D_00221820;
extern char D_0030A630[];
extern char D_0030A648[];

char D_00221800[8] = {0};
char D_00221808[8] = {0};
char D_00221810[8] = {0};
char D_00221818[8] = {0};

void func_004BC328(void) {
    s32 t;
    s32 id;

    func_004979A8(D_0030A630, D_00171B40[0].unkC, 0);
    func_004979A8(D_0030A648, D_00171B40[0].unk0, 0);
    func_00505238(func_004A1A60(&D_00221820, 0x26), D_0030A630);
    func_00505238(func_004A1A60(&D_00221820, 0x24), D_0030A648);
    func_00505328(func_004A1A60(&D_00221820, 0x26), 0x80808080);
    func_00505328(func_004A1A60(&D_00221820, 0x24), 0x80808080);
    t = *(s32 *)((char *)func_004FBF90(5, D_00171B40[0].unk36) + 0x14);
    id = func_004A1A60(&D_00221820, 0x2A);
    func_00505238(id, (void *)func_0045E038(t));
    func_00505328(func_004A1A60(&D_00221820, 0x2A), 0x80808080);
    func_0011D920(D_00221800, D_0021F918, D_00171B40[0].unk23);
    func_0011D920(D_00221808, D_0021F918, D_00171B40[0].unk21);
    func_0011D920(D_00221810, D_0021F918, D_00171B40[0].unk24);
    func_0011D920(D_00221818, D_0021F918, D_00171B40[0].unk25);
    func_00505238(func_004A1A60(&D_00221820, 0x18), D_00221800);
    func_00505238(func_004A1A60(&D_00221820, 0x19), D_00221808);
    func_00505238(func_004A1A60(&D_00221820, 0x1A), D_00221810);
    func_00505238(func_004A1A60(&D_00221820, 0x1B), D_00221818);
    func_00505328(func_004A1A60(&D_00221820, 0x18), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_00221820, 0x19), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_00221820, 0x1A), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_00221820, 0x1B), 0x80D0D0D0);
}
