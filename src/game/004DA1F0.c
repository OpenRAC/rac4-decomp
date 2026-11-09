#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    u8 pad8[0x130C - 0x8];
    u8 f130C[0x13A4 - 0x130C];
    u8 f13A4;
} Type1;

extern Type1 D_00321B98;

extern s32 func_004A1730(void *);
extern void func_004DA5E8(void);
extern void func_004DA740(void);
extern void func_004DA960(void);
extern void func_004DADD8(void);
extern void func_004DB350(void);
extern void func_004DB7B8(void);
extern s32 func_005014B0(s32 a0);

void func_004DA1F0(s32 a0) {
    switch (D_00321B98.f0) {
    case 0:
        D_00321B98.f0 = 2;
        break;
    case 2:
        func_004DADD8();
        break;
    case 1:
        func_005014B0(a0);
        break;
    }
    if (D_00321B98.f4 & 1) {
        func_004DA5E8();
    }
    func_004A1730(D_00321B98.f130C);
    if (D_00321B98.f4 & 2) {
        func_004DA740();
    }
    if (D_00321B98.f4 & 4) {
        func_004DA960();
    }
    func_004DB7B8();
    if (D_00321B98.f13A4 != 0) {
        func_004DB350();
    }
}
