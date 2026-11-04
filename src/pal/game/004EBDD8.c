#include "common.h"
extern s32 func_001588A8(s32), func_00157FA8(void);
extern void func_00489F30(void);
extern s32 func_0045DFC8(s16, s16, s16, s32, f32, f32, f32, f32);
extern s32 D_0021EE54;
typedef struct {
    char pad[0x4E00];
    u16 a;
    char gap[0xA];
    u16 b;
} State;
typedef struct {
    char pad[8];
    s16 a, b;
} Result;
extern State D_001F1480[];
extern Result D_00327A60[];
void func_004EBDD8(void)
{
    func_001588A8(0xCD);
    func_00489F30();
    func_00157FA8();
    if (D_0021EE54 != 1) {
        if (!D_001F1480[0].a)
            func_0045DFC8(0x2FAB, 0x680, 2, 0, 0.0f, 1.0f, 0.0f, 64.0f);
        else if (!D_001F1480[0].b)
            func_0045DFC8(0x2FAC, 0x681, 2, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    }
    D_00327A60[0].a = -1;
    D_00327A60[0].b = -1;
}
