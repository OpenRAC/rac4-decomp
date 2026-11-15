#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern void func_L00_007107F0(void *arg0, void *arg1);

extern s32 D_00220C8C;
extern s32 D_00220C90;
extern s32 D_00220CA4;
extern s32 D_00220CA8;

/* Initialises a menu object from a settings record and registers its default entries through its vtable. */
void func_L00_007168B0(u8 *arg0, u8 *arg1) {
    s32 v;
    s32 w;
    func_L00_007107F0(arg0, arg1);
    w = *(s32 *)(arg1 + 0x40);
    *(s32 *)(arg0 + 0x238) = 0;
    *(s32 *)(arg0 + 0x5C) = w;
    *(s32 *)(arg0 + 0x12C) = -1;
    *(s32 *)(arg0 + 0x130) = -1;
    *(s32 *)(arg0 + 0x134) = -1;
    *(s32 *)(arg0 + 0x138) = -1;
    *(s32 *)(arg0 + 0x13C) = -1;
    *(s32 *)(arg0 + 0x23C) = 0;
    if ((char *)(arg1 + 0x44) == 0) {
        arg0[0x60] = 0;
    } else {
        func_0011AFC8((char *)(arg0 + 0x60), (char *)(arg1 + 0x44), 0xC8);
        arg0[0x127] = 0;
    }
    v = *(s32 *)(arg1 + 0x10C);
    *(s32 *)(arg0 + 0x128) = v;
    arg0[0x3D3] = arg1[0x110];
    arg0[0x49C] = arg1[0x111];
    if (v >= 0xC8) {
        *(s32 *)(arg0 + 0x128) = 0xC7;
    }
    (*(void (**)(u8 *, s32))(*(u8 **)(arg0 + 0x58) + 0x100))(arg0, D_00220C8C);
    (*(void (**)(u8 *, s32))(*(u8 **)(arg0 + 0x58) + 0x100))(arg0, D_00220C90);
    (*(void (**)(u8 *, s32))(*(u8 **)(arg0 + 0x58) + 0x100))(arg0, D_00220CA4);
    (*(void (**)(u8 *, s32))(*(u8 **)(arg0 + 0x58) + 0x100))(arg0, D_00220CA8);
    (*(void (**)(u8 *, s32))(*(u8 **)(arg0 + 0x58) + 0xF8))(arg0, 0x20);
    arg0[0x240] = 0;
    arg0[0x49D] = arg1[0x112];
}
