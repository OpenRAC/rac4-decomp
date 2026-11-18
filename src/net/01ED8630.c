/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 {
    u16 f0;
    u8 pad2[6];
    s32 f8;
    s32 (*fC)(s32, s32);
    u32 f10;
    s32 (*f14)(s32, s32, s32);
    s32 f18;
} Type2;
struct Type1 {
    Type2 *f0;
    s32 f4;
};
typedef struct Type3 {
    s32 f0;
    u8 pad4[8];
    u32 fC;
} Type3;

extern s32 func_01ED8528(void);
extern void (*D_00199030[])(Type1 *);

/* Runs the request's per-block callbacks over each block; on success clears the object's bit for the request's id, else returns -0x15. */
s32 func_01ED8630(Type3 *arg0, Type1 *arg1) {
    Type1 loc;
    s32 id;
    s32 cnt;
    s32 w;
    s32 i;
    u32 step;
    s32 ok;

    if (arg0 == NULL) {
        return -0x15;
    }
    id = func_01ED8528();
    if (id == 0xFFFF) {
        return -0xC;
    }
    if (arg1->f0->f0 != id) {
        return -0xC;
    }
    cnt = arg1->f0->f18;
    w = arg0->f0;
    step = arg1->f0->f10;
    if (cnt >= 2) {
        step = step / cnt;
    }
    loc = *arg1;
    i = 0;
    if (cnt > 0) {
        do {
            if (arg1->f0->f14(2, w, loc.f4) == 0) {
                ok = 0;
                goto chk;
            }
            if (arg1->f0->fC(arg1->f4, arg1->f0->f8) == 0) {
                D_00199030[0](arg1);
                ok = 0;
                goto chk;
            }
            i++;
            loc.f4 += step;
        } while (i < cnt);
    }
    ok = 1;
chk:
    if (ok == 0) {
        return -0x15;
    }
    arg0->fC &= ~(1 << arg1->f0->f0);
    return 0;
}
