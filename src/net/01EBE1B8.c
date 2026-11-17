/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a, b; } P8;
typedef struct { char _p[8]; P8 p; s32 f10; } Rec;
typedef struct { P8 p; s32 f8; } Info;
typedef struct { char _p[0x38]; char *rec; } Own;
s32 func_01EBE1B8(Own *a, Rec *r, P8 *out, s32 *out2) {
    char *q = 0;
    Info *in;
    if (a == 0) {
        return 0xD2F2;
    }
    if (r != 0) {
        *out = r->p;
        *out2 = r->f10;
    } else {
        if ((char *)a + 0x2C != 0) {
            q = a->rec;
        }
        if (q == 0) {
            return 3;
        }
        in = (Info *)(q + 8);
        *out = in->p;
        *out2 = in->f8;
    }
    return 0;
}
