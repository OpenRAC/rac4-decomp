#include "common.h"

typedef struct Type2 Type2;
typedef struct Type3 {
    char _p0[0x14];
    void (*f14)(Type2 *);
    char _p18[8];
    void (*f20)(Type2 *, s32, s32);
} Type3;
struct Type2 {
    char _p0[4];
    s32 f4;
    char _p8[0x58 - 8];
    Type3 *f58;
};
typedef struct Type1 {
    char _p0[0xAC];
    s32 fAC;
    Type2 *fB0[1];
    char _pB4[0x230 - 0xB4];
    s32 f230;
} Type1;
typedef struct {
    s32 f0;
    void *f4;
} Manager;
extern Manager D_00223148[];
extern void func_001634A8(s32 repeat);
extern void func_L00_00698B08();
extern Manager *func_L00_00698D80();
extern s32 func_L00_0071B9B0(Type1 *arg0);

// Updates the menu's widgets and then the manager.
void func_L00_0071B478(Type1 *arg0) {
    s32 i;
    Manager *m;

    if (arg0->f230 >= 0) {
        if (arg0->fB0[arg0->f230]->f4 >= 5) {
            arg0->fB0[arg0->f230]->f58->f20(arg0->fB0[arg0->f230], 4, 0);
        }
    }
    func_L00_0071B9B0(arg0);
    for (i = 0; i < arg0->fAC; i++) {
        arg0->fB0[i]->f58->f14(arg0->fB0[i]);
    }
    func_001634A8(0);
    m = D_00223148;
    if (m->f4 == 0) {
        m = func_L00_00698D80();
    }
    func_L00_00698B08(m);
}
