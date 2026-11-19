/* cflags: @ee296 -O2 -G0 */
#include "common.h"
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; char rest[0xC]; } Entry;
extern Entry D_004C8BD8[];
void func_L00_005F3970(void) {
    Entry *p;
    p = D_004C8BD8;
    do {
        s32 timer;
        if (p->f0 == 0) {
            s32 next = p->fC + 1;
            p->fC = next < 11 ? next : 10;
        } else {
            p->fC = 0;
        }
        timer = p->f8;
        if (timer != 0) {
            timer--;
            p->f8 = timer;
            if (timer == 0) {
                p->f0 = 0;
            }
        }
        p++;
    } while ((s32)p < (s32)(D_004C8BD8 + 10));
}
