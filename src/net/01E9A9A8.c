/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0012A718();
extern void func_001294F0(char *, ...);
extern char D_001941B0[];
extern char D_00194330[];
extern char D_00194218[];
extern char D_00194290[];
extern s32 D_001AD3AC;
extern s32 D_001AD380;
extern s32 D_001AD200;
s32 func_01E9A9A8(s32 x) {
    s32 *res = &D_001AD200;
    if (D_001AD3AC == 0) {
        func_001294F0(D_001941B0, D_00194330);
        func_001294F0(D_00194218);
        return -1;
    }
    *res = x;
    func_0012A718(&D_001AD380, 4, 0, res, 4, res, 4, 0, 0);
    if (*res != -1) {
        func_001294F0(D_001941B0, D_00194330);
        func_001294F0(D_00194290, *res);
    }
    return *res;
}
