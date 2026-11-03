/* cflags: -mno-split-addresses */
#include "common.h"

typedef void (*Type1)(void *, f32);
extern s32 func_0048AA58(void *, s32, s32, Type1, void *);
extern void func_00439AA0(s32);
extern void func_004E3300(void);
extern void func_00489E20(void);
extern void func_004E17B8(void);
extern s32 func_00157FA8(void);
extern s32 func_00138D70(s32);
extern char D_002215D0[];

/* Flush active work and optionally wait for the transfer engine to finish. */
void func_004E5B78(s32 wait)
{
    func_0048AA58(D_002215D0, 1, 300, 0, 0);
    func_00439AA0(1);
    func_004E3300();
    func_00489E20();
    func_004E17B8();
    if (wait) {
        while (func_00157FA8())
            func_00138D70(0);
    }
}
