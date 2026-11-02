#include "common.h"
typedef struct {
    char p0[8];
    void *f8;
    void *fC;
} Type1;
extern Type1 D_0030A260[];
extern s32 D_00221890;
extern s32 func_00506BB8(void);
extern void func_0049D1E8(s32, s32, s32, s32);
extern void func_004B9EB8(void);
extern void func_0049AA18(void *);
extern void func_0049BE10(s32);

/* Resets the active state and releases its two associated objects. */
void func_004B8F28(void)
{
    s32 i = func_00506BB8();
    Type1 *p = &D_0030A260[i];
    func_0049D1E8(i, 0, D_00221890, 0);
    func_004B9EB8();
    if (p->f8) {
        func_0049AA18(p->f8);
        p->f8 = 0;
    }
    if (p->fC) {
        func_0049AA18(p->fC);
        p->fC = 0;
    }
    func_0049BE10(i);
}
