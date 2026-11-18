#include "common.h"

extern s32 D_001DFD9C[];
extern s32 D_0021DAB4;
extern s32 D_0021DAB0;
extern s32 D_0026B8E0[];
extern u8 D_00249450[];
extern u8 D_00249170[];
extern u8 D_0024CE70[];
extern u8 D_0024C6F0[];
extern u8 D_00331B00[];
extern u8 D_00331700[];
extern u8 D_0032A8E0[];
extern u8 D_0032A2E0[];
extern void func_00163898(void);
extern void func_L00_0067C410(void);
extern void func_L00_005CCCA8(void);
extern void func_L00_005BDCB8(void *, s32, s32);
extern void func_L00_005AD610(void);
extern void func_L00_005AD7A8(void);
extern void func_L00_005B3B58(void);
extern void func_L00_0067C528(void);
extern void func_L00_0060B668(void);
extern void func_L00_0067D0C0(void);
extern void func_L00_005E15D0(void);
extern void func_L00_005E1748(void);

// level init
void func_L00_005CCB40(void) {
    s32 i;

    func_00163898();
    func_L00_0067C410();
    func_L00_005CCCA8();
    D_0021DAB0 = D_001DFD9C[0];
    D_0021DAB4 = D_001DFD9C[0];
    func_L00_005BDCB8(D_00249450, -1, 0x2800);
    func_L00_005BDCB8(D_00249170, -1, 0x1E0);
    func_L00_005BDCB8(D_0024CE70, -1, 0xF00);
    func_L00_005BDCB8(D_0024C6F0, 0, 0xF0);
    func_L00_005BDCB8(D_00331B00, -1, 0x800);
    func_L00_005BDCB8(D_00331700, 0, 0x80);
    func_L00_005BDCB8(D_0032A8E0, -1, 0x400);
    func_L00_005BDCB8(D_0032A2E0, 0, 0x40);
    func_L00_005AD610();
    func_L00_005AD7A8();
    func_L00_005B3B58();
    func_L00_0067C528();
    func_L00_0060B668();
    func_L00_0067D0C0();
    func_L00_005E15D0();
    func_L00_005E1748();
    for (i = 0x7F; i >= 0; i--) {
        D_0026B8E0[i] = 0;
    }
}
