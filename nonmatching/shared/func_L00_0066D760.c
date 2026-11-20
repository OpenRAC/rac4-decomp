/* Not matching yet: BYTES 19/176 (tools/try_func.py func_L00_0066D760 --diff). Not part of the build. */
/* cflags: -O2 -G8 -fopt-stack */
#include "common.h"

typedef struct {
    u8 pad[0x2B0];
    s32 count;
    u32 list;
} S_1D2200;

typedef void (*Fn)(void *);

extern S_1D2200 D_1D2200;
extern u8 D_0032AD20[];
void func_L00_0066DA58(void *);

static s32 D_0066D760_flag = 0;

void func_L00_0066D760(void) {
    S_1D2200 *base;
    s32 i;
    s32 off;
    u8 *p;
    u8 *end;

    if (D_0066D760_flag == 0) {
        return;
    }
    base = &D_1D2200;
    for (i = 0, off = 0; i < base->count; i++, off += 0x90) {
        u8 *e = (u8 *)(off + base->list);
        Fn f = *(Fn *)(e + 4);
        if (f != NULL) {
            f(e);
        }
    }
    p = D_0032AD20;
    end = p + 0x3C0;
    do {
        if (p[0x40] != 0) {
            func_L00_0066DA58(p);
        }
        p += 0x50;
    } while ((s32)p < (s32)end);
}
