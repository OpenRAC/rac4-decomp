/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x1C]; s32 f20; } G;
typedef struct { char _p0[4]; s32 *f4; s32 f8; } Obj;
extern G *D_0016F8DC;
extern s32 D_0016F8E4;
extern s32 func_00126BD0();
void func_00152EC0(Obj *o) {
    *o->f4 = D_0016F8DC->f20;
    o->f8 = D_0016F8DC->f0;
    func_00126BD0(D_0016F8E4);
}
