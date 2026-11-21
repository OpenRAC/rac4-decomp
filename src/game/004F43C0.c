#include "common.h"

typedef struct Type171948 {
    u8 pad0[0x1C4];
    s32 f1C4;
    s32 f1C8;
    s32 f1CC;
} Type171948;

extern void func_00126E20(s32);
extern s32 func_00138D70(s32);
extern void func_0015ADA8(void);
extern void func_00161CF0(void);
extern void func_001634F0(f32);
extern s32 func_00163928(void);
extern void func_00448720(void);
extern s32 func_004636C8(void);
extern void func_00464B60(void);
extern void func_00466310(void);
extern void func_004E80F8(void);
extern void func_004F2680(void);
extern Type171948 D_00171948;
extern s32 D_0021EDD4;
extern f32 D_0021DE04;
extern u8 D_206948[];
u8 D_00220951 = 0;
void (*D_00220944)(void) = 0;

/* Runs the frame loop until the state at D_00171948 is ready, then calls the registered callback */
void func_004F43C0(void) {
    s32 w;

    if (D_00220951 == 0) {
        do {
            func_00126E20(0);
            func_00138D70(0);
            if (D_0021EDD4 == 1) {
                func_00161CF0();
                func_0015ADA8();
            }
            func_00466310();
            func_00464B60();
        } while ((D_00220951 = func_004636C8() != 0) == 0);
    }
    while (D_00171948.f1C4 != 2 || D_00171948.f1CC >= 0) {
        func_00126E20(0);
        func_00138D70(0);
        func_00466310();
        func_00464B60();
        if (D_0021EDD4 == 1) {
            func_00161CF0();
            func_0015ADA8();
        }
    }
    func_004F2680();
    w = 1;
    while (func_00163928() != 0) {
        func_00138D70(0);
        func_001634F0(D_0021DE04);
        if (D_0021EDD4 == w) {
            func_00161CF0();
            func_0015ADA8();
        }
    }
    D_206948[7] = 0;
    func_004E80F8();
    if (D_00220944 != NULL) {
        D_00220944();
    }
    func_00448720();
    if (D_0021EDD4 == 1) {
        func_00161CF0();
        func_0015ADA8();
    }
}
