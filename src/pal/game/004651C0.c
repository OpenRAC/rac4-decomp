/* cflags: -O2 -G8 */
#include "common.h"

void func_001633C8(s32 value);
void func_00453E20(void *destination, s32 value, s32 bytes);
void func_00453E48(void *destination, s32 bytes);
void func_0046F9B0(void);
s64 func_0046FFD8(void);
s32 func_004795A8(s32 value);

extern s32 D_00171DB8[];
extern f32 D_0021DE70;
extern s32 D_0021EE54;
extern s32 D_00229B80[];
extern u8 D_002481E0[];
extern u8 D_002641E0[];
extern s32 D_003367B8[];

typedef struct {
    u8 unknown[0x10];
    s32 field_10;
    s32 field_14;
} StateView;
extern StateView D_00239840;

void func_004651C0(void)
{
    func_00453E20(D_003367B8, 0, sizeof(s32));
    func_00453E20(D_00229B80, 0, 0x1D0);
    func_0046F9B0();
    func_0046FFD8();
    if (D_0021EE54 != 1) {
        func_001633C8(0x4D2);
    }
    if (D_00171DB8[0]) {
        if (D_0021DE70 == 1.0f) {
            func_004795A8(1);
        }
    } else if (D_0021DE70 != 1.0f) {
        func_004795A8(0);
    }
    D_00239840.field_10 = 0;
    D_00239840.field_14 = 0;
    func_00453E48(D_002481E0, 0x1C000);
    func_00453E48(D_002641E0, 0xC0);
}
