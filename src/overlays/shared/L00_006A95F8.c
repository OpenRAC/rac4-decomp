#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    s32 f1C;
    s32 f20;
    u8 pad24[0x228 - 0x24];
    s32 f228;
    u8 pad22C[0x258 - 0x22C];
    s32 f258;
    s32 f25C;
    u8 pad260[0x6C9 - 0x260];
    u8 f6C9;
} Type1;

extern Type1 D_00172160;
extern s8 D_00171DF4[];

extern void func_0015A170(s32);
extern s32 func_0015AA58(void);
extern void func_L00_00702CA8(void);
extern void func_L00_006AA088(void);
extern void func_L00_006AA0D8(s32, s32);
extern void func_L00_006F17F0(void);
extern void func_L00_006EBE20(void);
extern void func_L00_006F5998(void);
void func_L00_006A95F8(void) {
    D_00172160.f258 = 1;
    D_00172160.f25C = 1;
    D_00172160.f1C = 1;
    D_00172160.f228 = 0;
    D_00172160.f6C9 = 0;
    func_0015A170(0);
    func_0015AA58();
    if (D_00172160.f20 >= 2) {
        D_00171DF4[0] = 0;
    }
    func_L00_00702CA8();
    func_L00_006AA088();
    func_L00_006AA0D8(0, 0);
    func_L00_006F17F0();
    func_L00_006EBE20();
    func_L00_006F5998();
}
