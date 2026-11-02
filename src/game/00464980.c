/* cflags: -O2 -G8 */
#include "common.h"

void func_001633C0(s32 value);
void func_00453608(void *destination, s32 value, s32 bytes);
void func_00453630(void *destination, s32 bytes);
void func_0046F0D0(void);
s64 func_0046F6F8(void);
s32 func_00478C80(s32 value);

extern s32 D_00171D38[];
extern f32 D_0021DDE8;
extern s32 D_0021EDD4;
extern s32 D_00229A80[];
extern u8 D_002480E0[];
extern u8 D_002640E0[];
extern s32 D_003367B8[];

typedef struct {
    u8 unknown[0x10];
    s32 field_10;
    s32 field_14;
} StateView;
extern StateView D_00239740;

void func_00464980(void)
{
    func_00453608(D_003367B8, 0, sizeof(s32));
    func_00453608(D_00229A80, 0, 0x1D0);
    func_0046F0D0();
    func_0046F6F8();
    if (D_0021EDD4 != 1) {
        func_001633C0(0x4D2);
    }
    if (D_00171D38[0]) {
        if (D_0021DDE8 == 1.0f) {
            func_00478C80(1);
        }
    } else if (D_0021DDE8 != 1.0f) {
        func_00478C80(0);
    }
    D_00239740.field_10 = 0;
    D_00239740.field_14 = 0;
    func_00453630(D_002480E0, 0x1C000);
    func_00453630(D_002640E0, 0xC0);
}
