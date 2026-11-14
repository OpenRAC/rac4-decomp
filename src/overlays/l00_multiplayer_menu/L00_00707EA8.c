#include "common.h"

extern void func_0015ADA8(void);
extern void func_L00_00708258(void);
extern void func_L00_0061E178(void);
extern void func_L00_0061E1C0(s32);
extern void func_L00_0066B1A8();
extern void func_L00_00774710(s32);
extern void *D_00220D14;
extern s32 D_002233A4;

/* runs the setup calls, then calls the method at 0x138 of the object at 0x58 of D_00220D14 when it is set */
void func_L00_00707EA8(void) {
    void *var_a0;

    func_0015ADA8();
    func_L00_00708258();
    func_L00_0061E178();
    func_L00_0061E1C0(4);
    func_L00_0061E1C0(0);
    func_L00_0066B1A8();
    if (D_002233A4 == 0) {
        var_a0 = D_00220D14;
    } else {
        func_L00_00774710(D_002233A4);
        var_a0 = D_00220D14;
    }
    if (var_a0 != NULL) {
        (*(void (**)(void *))((u8 *)*(void **)((u8 *)var_a0 + 0x58) + 0x138))(var_a0);
    }
}
