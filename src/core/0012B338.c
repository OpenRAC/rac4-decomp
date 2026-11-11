/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_00123430 (src/boot_elf/core/123430.c, GPL-3.0), the same code in both games. */

extern int func_00126BB0();
extern s32 func_00126BB0(s32);
extern s32 func_00126BC0(s32);
extern s32 D_00164730;
extern u8 D_001A9040[];
extern s32 D_00164724[];
typedef struct {
    s32 sema;
    void *res;
    s32 x8;
    s32 flags;
    s32 mode;
    char name[0x400];
    s32 fd;
} OpenArg_123430;
typedef struct {
    s32 res;
    s32 flags;
} Fd_123430;
typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_123430;
extern OpenArg_123430 D_001A7B40;
extern u8 D_001A9040[];
extern u8 D_001A9240[];
extern u8 D_001A8780[];
extern char D_001930C0[];
extern s32 D_00164730;
extern s32 func_0012AFE0(void);
extern void func_0012B068(void);
extern s32 func_0012B270(void);
extern void func_0012B010(void);
extern Fd_123430 *func_0012A9E8(void);
extern s32 func_00126BA0(Sema_123430 *);
extern s32 func_00126BE0(s32);
extern s32 func_0012AA70(void *, s32, s32, void *, s32, void *, s32, void *, void *, s32);
s32 func_0012B338(const char *name, s32 flags, ...) {
    char *ap;
    OpenArg_123430 *arg;
    Fd_123430 *fd;
    s32 idx;
    s32 i;
    s32 s;
    s32 ok;
    s32 mode;
    Sema_123430 sp;
    s32 res[4];
    arg = &D_001A7B40;
    ((s32 (*)(s32))func_0012AFE0)(0);
    if (D_00164724[0] == 0) {
        func_0012B068();
    }
    if (func_0012B270() != 0) {
        func_0012B010();
        return 0xFFFEFFFC;
    }
    fd = func_0012A9E8();
    if (fd == 0) {
        func_0012B010();
        return -0x13;
    }
    ap = (char *)__builtin_next_arg(flags)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    mode = *(s32 *)ap;
    i = 0;
    if ((arg->name[0] = name[0]) != 0) {
        while (++i < 0x400) {
            if ((arg->name[i] = name[i]) == 0) break;
        }
    }
    if (i == 0x400) {
        arg->name[0x3FF] = 0;
    }
    idx = ((u8 *)fd - D_001A9040) >> 4;
    arg->flags = flags & 0x7FFFFFFF;
    arg->mode = mode;
    sp.option = 1;
    sp.name = D_001930C0;
    arg->fd = idx;
    sp.init_count = 0;
    s = func_00126BA0(&sp);
    arg->res = res;
    arg->sema = s;
    arg->x8 = 4;
    if (func_0012AA70(D_001A9240, 0, 0, &D_001A7B40, 0x418, D_001A8780, 4, 0, 0, 0) < 0) {
        func_00126BB0(s);
        func_0012B010();
        return -0xB;
    }
    ok = *(s32 *)((u32)D_001A8780 | 0x20000000);
    func_0012B010();
    if (ok == 0) {
        func_00126BB0(s);
        return -0xB;
    }
    func_00126BE0(s);
    func_00126BB0(s);
    if (res[0] < 0) {
        func_00126BE0(D_00164730);
        fd->flags = 0;
        func_00126BC0(D_00164730);
        return res[0];
    }
    ok = idx;
    func_00126BE0(D_00164730);
    fd->res = res[0];
    fd->flags |= flags;
    func_00126BC0(D_00164730);
    return ok;
}
extern s32 func_0012AA70();
extern u8 D_001A9240[];
