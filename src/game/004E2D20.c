/* cflags: -mno-split-addresses */
#include "common.h"

void func_004E3C40(void);
s32 func_004E3DA8(s32);
void func_004E7B88(void);
extern s32 D_0021DA30;
extern s32 D_00221D34;
extern s32 *D_00221D2C;
extern s32 *D_00221E20;

void func_004E2D20(void)
{
    s32 *s1;
    s32 n;

    s1 = D_00221E20;
    D_00221E20 = s1 + 4;
    D_00221D2C[0] = 0x20000000;
    D_00221D2C[1] = (s32)D_00221E20;
    D_00221D2C[2] = 0;
    D_00221D2C[3] = 0;
    func_004E3C40();
    n = func_004E3DA8(D_0021DA30);
    func_004E7B88();
    if (D_00221D34 < n) {
        D_00221D34 = n;
    }
    D_00221E20[0] = 0x20000000;
    D_00221E20[1] = (s32)(D_00221D2C + 4);
    D_00221E20[2] = 0;
    D_00221E20[3] = 0;
    D_00221E20 += 4;
    s1[0] = 0x20000000;
    s1[1] = (s32)D_00221E20;
    s1[2] = 0;
    s1[3] = 0;
}
