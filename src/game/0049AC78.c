#include "common.h"

typedef struct {
    s32 f0;
    void (*f4)(s32);
    s32 f8;
    s32 fC;
} Type1;

extern void func_00497E10(s32);
extern s32 func_00505B20(void);
extern s32 D_0021EDCC, D_0021EDD4, D_0021EDD8, D_2215A4;
extern Type1 D_003D8E68[];
extern s16 D_1F362C[];
extern u8 D_306DC0[];

// Pop and run every pending callback of the D_306DC0 entry of the current slot, then call func_00497E10.
void func_0049AC78(void) {
    s32 id = func_00505B20();
    u8 *entry = D_306DC0 + id * 0x3C;
    void (*fn)(s32);
    Type1 *e;
    D_1F362C[0] = 0;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        D_0021EDCC = D_2215A4;
    }
    while (*(s32 *)(entry + 0xC) > 0) {
        *(s32 *)(entry + 0xC) -= 1;
        e = &D_003D8E68[*(s32 *)(entry + 0xC)];
        fn = e->f4;
        if (fn != 0) {
            fn(id);
        }
    }
    func_00497E10(id);
}
