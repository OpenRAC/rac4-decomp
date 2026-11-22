/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10[3];
} Ent;

extern Ent D_004C8A98[10];

void func_L00_005F0F58(void) {
    Ent *p = D_004C8A98;
    s32 t;
    Ent *end = D_004C8A98 + 10;

    do {
        if (p->f0 == 0) {
            s32 v = p->fC + 1;
            p->fC = (v < 11) ? v : 10;
        } else {
            p->fC = 0;
        }
        t = p->f8;
        if (t != 0) {
            t--;
            p->f8 = t;
            if (t == 0) {
                p->f0 = 0;
            }
        }
        p++;
    } while ((s32)p < (s32)end);
}
