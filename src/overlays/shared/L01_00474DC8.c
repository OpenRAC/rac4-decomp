/* cflags: @ee29 -O2 -G8 */
#include "common.h"
typedef struct P { char _p0[0x10]; s32 f10; } P;
typedef struct O { char _p0[0x20]; u8 f20; char _p21[3]; P *f24; char _p28[0x98 - 0x28]; s32 f98; char _p9C[0xBC - 0x9C]; s16 fBC; } O;
O *D_00221980;
void func_L01_00474DC8(s32 arg0) {
    O *o = D_00221980;
    if (o != NULL && o->f20 != 0xFE && o->f20 != 0xFD && o->fBC == 0x2748) {
        if (arg0 != 0) {
            o->f98 = o->f24->f10;
        } else {
            o->f98 = 0;
        }
    }
}
