/* cflags: -mno-split-addresses */
#include "common.h"

void func_0046C7D0(void *arg0, s32 arg1);
void func_0046D498(u8 arg0, void *arg1);
s32 func_0046D590(u8 arg0);
void func_0046F448(void *arg0);
void func_0046F8C8(void *arg0);
void func_00470260(s32 arg0);
void func_00470410(void *arg0, s32 arg1);
extern s32 D_0021DDB8;
extern u32 D_0022140C[];
extern s32 D_00221418;
extern s32 D_0022141C[];

typedef struct {
    u8 pad0[0x20];
    u8 unk20;
    u8 unk21;
    u8 pad22[0x2D - 0x22];
    u8 unk2D;
    u8 pad2E[0x5C - 0x2E];
    s32 unk5C;
    u8 pad60[0xA0 - 0x60];
    s32 unkA0;
    u8 padA4[0xAC - 0xA4];
    s32 unkAC;
} Obj;

void func_0046BDD0(Obj *arg0) {
    s32 a;

    arg0->unk2D++;
    if ((u32)arg0 < D_0022140C[0]) {
        arg0->unk20 = 0xFD;
    } else {
        arg0->unk20 = 0xFE;
        if (func_0046D590(arg0->unk21) != 0) {
            func_0046D498(arg0->unk21, arg0);
        }
        a = arg0->unkAC;
        if (a != 0 && a >= D_00221418 && a < D_00221418 + (D_0022141C[0] << 6)) {
            func_00470260(a);
            arg0->unkAC = 0;
        }
        while (arg0->unk5C != 0) {
            func_0046C7D0(arg0, arg0->unk5C);
        }
    }
    arg0->unkA0 = D_0021DDB8 + 2;
    func_00470410(arg0, 0x80807F7F);
    func_0046F8C8(arg0);
    func_0046F448(arg0);
}
