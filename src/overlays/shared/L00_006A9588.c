#include "common.h"

extern s8 D_00171DF4[];
extern s32 D_0021DDC8;
extern s8 D_00220490;

extern void func_0015EEF0(s32 arg);
extern void func_0015EEF8(s32 arg);
extern void func_L00_006EE930(void);
extern void func_L00_006EF228(void);
extern void func_L00_00702CA8(void);
extern void func_L00_006A9690(void);
extern void func_L00_006AA088(void);
extern void func_L00_006F17F0(void);
extern void func_L00_006EBE20(void);
extern void func_L00_006F5998(void);

void func_L00_006A9588(void) {
    D_00171DF4[0] = 0;
    D_0021DDC8 = 5;
    func_0015EEF0((s32)func_L00_006EE930);
    func_0015EEF8((s32)func_L00_006EF228);
    func_L00_00702CA8();
    func_L00_006A9690();
    func_L00_006AA088();
    func_L00_006F17F0();
    D_00220490 = 0;
    func_L00_006EBE20();
    func_L00_006F5998();
}
