/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void func_L00_0051A148(s32, s8 *, s8 *, s8 *, s8 *);
extern s8 D_004AFDD8[];
extern s8 D_004AFDE0[];
extern s8 D_004AFDE8[];
extern s8 D_004AFDF8[];

void func_L00_00536348(s32 arg0, s32 arg1) {
    s8 buf0[16];
    s8 buf1[16];

    func_0011D920(buf0, D_004AFDD8, arg0);
    func_0011D920(buf1, D_004AFDE0, arg1);
    func_L00_0051A148(4, D_004AFDE8, buf0, D_004AFDF8, buf1);
}
