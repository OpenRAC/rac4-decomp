/* cflags: @ee296 -O2 -G0 */

#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Rec;

extern Rec D_1B7918;
extern s32 (*D_001994D0[])();

/* Publish the four values into the shared record, let the installed hook derive
   the 0xC field and hand the record back through OUT. */
s32 func_01ED9AC8(s32 **out, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    Rec *r;
    s32 res = -21;

    if (a1 == 0 && a4 != 0 && a2 != 0 && out != 0) {
        r = &D_1B7918;
        r->f0 = a4;
        r->f4 = a5;
        r->f10 = a3;
        r->f8 = a2;
        res = D_001994D0[0](a2);
        *out = (s32 *)r;
        r->fC = res;
        res = 0;
    }
    return res;
}
