/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s8 f8; s8 f9; char _pA[6]; u32 f10; s16 f14; char f16[1]; } Msg;
typedef void (*Cb)(s32, u32 *, s32);
extern char D_00169C48[];
extern char D_00197EF8[];
extern char D_00169BC8[];
extern s32 D_00169BBC;
extern Cb D_00169C90;
extern s32 func_0011D920(char *, const char *, ...);
extern char *func_0011AFC8(char *, const char *, s32);
void func_01ED46A8(s32 a, s32 b, s32 c, Msg *m) {
    u32 x;
    s32 k;
    s32 id = m->f0;
    func_0011D920(D_00169C48, D_00197EF8, m->f8, m->f9);
    func_0011AFC8(D_00169BC8, m->f16, m->f14);
    k = m->f4;
    if (k == 0) {
        x = m->f10;
        if (x < 4) {
            if (x >= 2) {
                D_00169BBC = 2;
            }
        }
    } else {
        x = 0;
    }
    if (D_00169C90 != 0) {
        D_00169C90(k, &x, id);
    }
}
