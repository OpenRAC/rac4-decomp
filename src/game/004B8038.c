#include "common.h"
typedef struct {
    char p0[8];
    void *f8;
    void *fC;
} Type1;
extern Type1 D_0030A160[];
extern s32 D_00221790;
extern s32 func_00505B20(void);
extern void func_0049C4B0(s32, s32, s32, s32);
extern void func_004B8FC8(void);
void func_00499CE0(s32 arg0);
void func_0049B0D8(s32 arg0);

/* Resets the active state and releases its two associated objects. */
void func_004B8038(void)
{
    s32 i = func_00505B20();
    Type1 *p = &D_0030A160[i];
    func_0049C4B0(i, 0, D_00221790, 0);
    func_004B8FC8();
    if (p->f8) {
        func_00499CE0(p->f8);
        p->f8 = 0;
    }
    if (p->fC) {
        func_00499CE0(p->fC);
        p->fC = 0;
    }
    func_0049B0D8(i);
}
