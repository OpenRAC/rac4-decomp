/* cflags: -mno-split-addresses */
#include "common.h"

typedef void (*Type1)(void *, f32);
extern s32 func_00489FA0(void *, s32, s32, Type1, void *);
extern void func_004394A8(s32);
extern void func_004E23A0(void);
extern void func_00489368(void);
extern void func_004E0858(void);
extern s32 func_00157F98(void);
extern s32 func_00138D70(s32);
extern char D_002214D0[];

/* Flush active work and optionally wait for the transfer engine to finish. */
void func_004E4C50(s32 wait)
{
    func_00489FA0(D_002214D0, 1, 300, 0, 0);
    func_004394A8(1);
    func_004E23A0();
    func_00489368();
    func_004E0858();
    if (wait) {
        while (func_00157F98())
            func_00138D70(0);
    }
}
