/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x410];
    s64 f410;
    u8 pad1[0x106F8 - 0x418];
    s32 f106F8;
} Type1;

extern int func_0012E978(s64 arg0, void *f8, void *arg);
extern Type1 D_004885B0[];
extern s32 D_00498D84[];
extern void func_L00_004F3E9C(void);

/* Opens a handle on the context at D_004885B0+0x410 into D_00498D84 when none is open yet; returns it, or -1. */
s32 func_L00_004F3ED8(void) {
    Type1 *c = D_004885B0;
    s32 *h;
    s32 r;

    if (c->f410 != 0) {
        h = D_00498D84;
        if (*h < 0) {
            if (c->f106F8 == 0) {
                r = func_0012E978(c->f410, (u8 *)func_L00_004F3E9C + 4, 0);
                *h = r;
                return r;
            }
        }
    }
    return -1;
}
