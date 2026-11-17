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
    s32 f28;
} Obj;
void *func_004033B0(s32);
extern void func_00403210(void *);
extern void func_004075B8(void);
Obj *func_00407360(Obj *o, s32 a, s32 b, s32 c) {
    if (o == 0) {
        o = func_004033B0(0x2C);
        if (o == 0) {
            return 0;
        }
    }
    o->f4 = a;
    o->f0 = 0;
    func_00403210(o->f1C);
    o->f18 = func_004075B8;
    o->f10 = b;
    o->f14 = c;
    o->f28 = 0;
    return o;
}
