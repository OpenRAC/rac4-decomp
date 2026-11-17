#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    u8 pad[0xAD0 - 0x10];
} S1;

extern void func_0011A518(void *, s32, s32);
extern s32 func_0015C748(void);
extern u8 func_0015C770(void);
extern S1 D_01F31380[];
extern s32 D_001722F8[];
extern s32 D_0021DE10;
s32 D_0021DFEC = 0;

// Reset every slot whose key no longer matches, then publish the pending value.
void func_0015E7A8(void) {
    S1 *p;
    S1 *end;

    p = D_01F31380;
    end = p + 10;
    D_0021DFEC = 0;
    do {
        if (func_0015C770() == 0 || p->f0 != func_0015C748()) {
            func_0011A518(p, 0, 0xAD0);
            p->f0 = -1;
            p->f8 = 0;
            p->fA = 0;
            p->fE = 0;
            p->f4 = 0;
        }
        p++;
    } while ((s32)p < (s32)end);
    if (D_0021DE10 != 0) {
        D_001722F8[0] = D_0021DE10;
    }
}
