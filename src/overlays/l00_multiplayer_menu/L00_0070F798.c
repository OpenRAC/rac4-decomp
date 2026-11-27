#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_001614A8(void);
extern s32 func_01E9E5D0(s32 arg0, s32 arg1);
extern void func_L00_00709AC8(void *);

extern char D_00220BC0[];
extern char D_00220BD0[];
extern s32 D_003F41D8[];
extern s32 D_172160[];

s32 D_00220B18 = 0;
s32 D_00220B0C = 0;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0xF];
    char f1B[0x185];
} Type1;

typedef struct {
    s8 a;
    s8 b;
} Two;

void func_L00_0070F798(s32 arg0, s32 arg1) {
    Type1 rec;
    s32 tmp;

    rec.f0 = D_003F41D8[0];
    rec.f4 = 1;
    rec.f8 = arg0;
    if (arg1 != 0) {
        tmp = -1;
        if (D_00220B18 == 1) {
            func_01E9E5D0((s32)&tmp, D_172160[3]);
        }
        func_0011D920(rec.f1B, D_00220BC0,
                      func_001614A8() != 0 ? 0x2B : 0x2D,
                      D_172160[5] == 1 ? 0x31 : 0x32,
                      D_00220B0C, tmp);
    } else {
        *(Two *)rec.f1B = *(Two *)D_00220BD0;
    }
    func_L00_00709AC8(&rec);
}
