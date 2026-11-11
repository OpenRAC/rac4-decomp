/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } F_12B5C8;
typedef struct { s32 x0; void *x4; s32 x8; s32 xC; s32 x10; } P_12B5C8;
typedef struct { s32 count; s32 max; s32 init; s32 wait; u32 attr; void *option; } Q_12B5C8;

extern F_12B5C8 *func_0012AB60(s32);
extern s32 func_0012AFE0(s32);
extern void func_0012B010(void);
extern s32 func_00126BA0(Q_12B5C8 *);
extern s32 func_00126BB0(s32);
extern void func_00126BE0(s32);
extern s32 func_0012AA70(void *, s32, s32, void *, s32, void *, s32, s32, s32, s32);
extern s32 D_00164724[];
extern F_12B5C8 D_001A9040[];
extern P_12B5C8 D_001A7B40;
extern u8 D_001A9240[];
extern s32 D_001A8780[];
extern char D_001930D8[];

/* from rac3-decomp's func_001236C0 */
s32 func_0012B5C8(s32 fd) {
    F_12B5C8 *f;
    Q_12B5C8 q;
    s32 res;
    s32 s;
    s32 r;
    P_12B5C8 *p = &D_001A7B40;
    f = func_0012AB60(fd);
    func_0012AFE0(1);
    if (D_00164724[0] == 0 || f == 0 || f->x4 == 0) {
        func_0012B010();
        return -9;
    }
    p->xC = f->x0;
    p->x10 = f - D_001A9040;
    q.max = 1;
    q.init = 0;
    q.option = D_001930D8;
    s = func_00126BA0(&q);
    p->x0 = s;
    p->x4 = &res;
    p->x8 = 4;
    if (func_0012AA70(D_001A9240, 1, 0, p, 0x14, D_001A8780, 4, 0, 0, 0) < 0) {
        func_00126BB0(s);
        func_0012B010();
        return -11;
    }
    f->x4 = 0;
    r = *(s32 *)((u32)D_001A8780 | 0x20000000);
    func_0012B010();
    if (r == 0) {
        func_00126BB0(s);
        return -11;
    }
    func_00126BE0(s);
    func_00126BB0(s);
    if (res < 0) {
        return res;
    }
    return 0;
}
