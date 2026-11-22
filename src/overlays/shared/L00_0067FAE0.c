#include "common.h"
typedef struct { u8 pad[0xE]; s16 a; u8 pad2[0x30]; u8 b; } S;
extern void func_004594C8(s32);
extern void func_00449BF8(s32, s32, s32, s32);
extern void func_L00_005AECE8(s32);
extern s32 D_00222188;
extern S D_003348E0;
void func_L00_0067FAE0(void) {
    func_004594C8(0);
    func_00449BF8(0, 0, 0, 0x80);
    if (D_003348E0.a != 0) {
        D_00222188 = 0x100FF;
    } else {
        D_00222188 = 0x70;
    }
    func_L00_005AECE8(0);
    if (D_003348E0.b != 0) {
        func_00449BF8(0, 0, 0, D_003348E0.b);
    }
}
