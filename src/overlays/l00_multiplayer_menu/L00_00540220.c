#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;
extern u8 D_00547EC8[];
extern void func_00547F20(void);
extern S_00504410 *func_L00_00517808(void);

/* from rac3-decomp's func_L39_00504410 */
s32 func_L00_00540220(void) {
    S_00504410 *p = func_L00_00517808();
    p->f20 = D_00547EC8;
    p->f24 = func_00547F20;
    p->f28 = 0;
    p->f2C = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f38 = 0;
    return 1;
}
