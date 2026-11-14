/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x1C]; s32 f20; char _p24[0xC]; char f30[4]; } G;
typedef struct { void *f0; s32 *f4; s32 f8; } Obj;
extern G *D_0016F8DC;
extern s32 D_0016F8E4;
extern s32 func_00126BD0();
extern void func_0011A370(void *, void *, s32);
void func_00152E58(Obj *o) {
    func_0011A370(o->f0, D_0016F8DC->f30, D_0016F8DC->f20);
    *o->f4 = D_0016F8DC->f20;
    o->f8 = D_0016F8DC->f0;
    func_00126BD0(D_0016F8E4);
}
