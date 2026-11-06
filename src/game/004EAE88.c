#include "common.h"

extern s32 func_00157F98(void);
extern void func_00158898(s32 arg0);
extern void func_00489478(void);
extern void func_0045D7B0(s32, s32, s32, s32, f32, f32, f32, f32);

typedef struct Type1 {
    u8 pad0[0x4E00];
    u16 f4E00;
    u8 pad4E02[0xA];
    u16 f4E0C;
} Type1;

typedef struct Type2 {
    u8 pad0[0x8];
    s16 f8;
    s16 fA;
} Type2;

extern s32 D_0021EDD4;
extern Type1 D_001F1400[];
extern Type2 D_00327A60[];

void func_004EAE88(void) {
    func_00158898(0xCD);
    func_00489478();
    func_00157F98();
    if (D_0021EDD4 != 1) {
        if (D_001F1400[0].f4E00 == 0) {
            func_0045D7B0(0x2FAB, 0x680, 2, 0, 0.0f, 1.0f, 0.0f, 64.0f);
        } else if (D_001F1400[0].f4E0C == 0) {
            func_0045D7B0(0x2FAC, 0x681, 2, 0, 0.0f, 1.0f, 0.0f, 64.0f);
        }
    }
    D_00327A60[0].f8 = -1;
    D_00327A60[0].fA = -1;
}
