#include "common.h"

typedef struct {
    u8 f0;
    s32 f4;
    void *f8;
    u32 fC;
    s32 f10[3];
    s32 f1C;
    void *f20;
    u32 f24;
} Type2;

extern void func_L00_00775600(void *arg0);

/* resets an object: invalidates ids, releases two sub-objects, clears fields */
void func_L00_00775868(Type2 *arg0) {
    arg0->fC = 0xFFFFFFFF;
    arg0->f24 = 0xFFFFFFFF;
    func_L00_00775600(arg0->f8);
    func_L00_00775600(arg0->f20);
    arg0->f1C = 0;
    arg0->f4 = 0;
    arg0->f0 = 0;
}
