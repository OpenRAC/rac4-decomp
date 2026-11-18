/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    char _p8[8];
    s32 f10;
    s32 f14;
    void *f18;
    char f1C[0xC];
} Obj;
void *func_004033B0(s32);
extern void func_00403210(void *);
extern void func_00407250(void);
Obj *func_00407110(Obj *o, s32 a, s32 b, s32 c) {
    if (o == 0) {
        o = func_004033B0(0x28);
        if (o == 0) {
            return 0;
        }
    }
    o->f4 = a;
    o->f0 = 0;
    func_00403210(o->f1C);
    o->f18 = func_00407250;
    o->f10 = b;
    o->f14 = c;
    return o;
}
