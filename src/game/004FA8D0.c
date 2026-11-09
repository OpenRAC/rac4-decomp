#include "common.h"

extern void func_004F8DF8(s32 arg0, const void *arg1);
extern void func_004FA100(s32 **pp, s32 *size);

extern s32 D_0021DF20;
extern s32 D_0021DF24;
extern s32 D_0021DF2C;
extern s32 D_0020E300[];
extern s32 D_0020E400[];
extern s32 *D_00221E20;
extern s32 D_00221F70;
extern s32 D_00221F78;
extern s32 D_00221F7C;
extern s32 D_00328F00[];

s32 D_002209BC = 0;

void func_004FA8D0(void) {
    s32 *p;
    s32 size;
    s32 end;

    D_002209BC = 0x6000;
    D_00221E20[0] = (D_0021DF20 >> 4) | 0x30000000;
    D_00221E20[1] = (s32)D_0020E300;
    D_00221E20[2] = D_00221F70 | 0x03000000;
    D_00221E20[3] = 0x02000000;
    size = 0;
    D_00221E20 += 4;
    p = D_00221E20 + 4;
    D_00221F70 += D_00221F78;
    func_004FA100(&p, &size);
    end = (s32)p - 0x10;
    D_00221E20[0] = ((end - (s32)D_00221E20) >> 4) | 0x10000000;
    D_00221E20[2] = D_00221F70 | 0x03000000;
    D_00221E20[3] = 0x02000000;
    D_00221F70 += size;
    D_00221E20 = p;
    func_004F8DF8(D_0021DF2C, D_00328F00);
    D_00221E20[0] = (D_0021DF24 >> 4) | 0x30000000;
    D_00221E20[1] = (s32)D_0020E400;
    D_00221E20[2] = D_00221F70 | 0x03000000;
    D_00221E20[3] = 0x02000000;
    D_00221F70 += D_00221F7C;
    D_00221E20 += 4;
}
