#include "common.h"
typedef struct { char pad[0x2c]; int value; char rest[0x1d0]; } Type1;
extern Type1 D_00307254[];
extern int func_00505B20(void);
extern void func_0049F828(int, int, float *, float *, float *, float *);
extern void func_0049BFC0(int, int, int, float, float, float, float);
extern void func_00505328(unsigned int, unsigned int);
static inline unsigned int add(unsigned int a, unsigned int b) { return a + b; }
/* Computes and submits four values and a color. */
void func_0049FA38(void) {
    float a, b, c, d;
    int i = func_00505B20();
    Type1 *p = &D_00307254[i];
    func_0049F828(i, p->value, &a, &b, &c, &d);
    func_0049BFC0(i, 0, 0, a, b, c, d);
    func_00505328(add((unsigned int)i << 6, add((unsigned int)p->value << 1, 0x14000eu)), 0x80d0d0d0);
}
