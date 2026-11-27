/* Not matching yet: BYTES 8/160 (tools/try_func.py func_00137058 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern int D_00165FD4;
extern int D_00165FE0;
extern int D_00165FE8;
extern int D_00165FEC;
extern int D_00165FF0;
extern int D_00166020;

extern int func_00126BB0();
extern void func_00126BC0(int);
extern void func_00129990(int);
extern int func_0012D420();
extern void func_0012D470();

void func_00137058(void)
{
    int temp;

    if (D_00165FD4 != 0) {
        s32 n = -1;
        D_00166020 = n;
        func_00126BC0(D_00165FE0);
    }
    func_00126BB0(D_00165FE8);
    func_00126BB0(D_00165FEC);
    func_00126BB0(D_00165FF0);
    func_00126BB0(D_00165FE0);
    temp = func_0012D420();
    func_00129990(0x80000012);
    if (temp != 0) {
        func_0012D470();
    }
}
