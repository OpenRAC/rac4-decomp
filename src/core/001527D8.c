/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011D5D8(const char *fmt,...);
extern void func_00126BC0(s32);
extern s32 func_00126BE0(s32);
extern s32 func_0012A718();
extern s32 *D_0016F8DC[];
extern s32 D_0016F8E4[];
extern char D_001A3E88[];
extern char D_1B9300[];

/* Sends request 3 with arg0 through the shared buffer and returns its result word. */
s32 func_001527D8(s32 arg0) {
    s32 r;
    if (D_0016F8E4[0] == -1) {
        return 0x8000000A;
    }
    func_00126BE0(D_0016F8E4[0]);
    D_0016F8DC[0][3] = arg0;
    if (func_0012A718(D_1B9300, 3, 0, D_0016F8DC[0], 0x20, D_0016F8DC[0], 0x20, 0, 0) == 0) {
        r = D_0016F8DC[0][0];
        func_00126BC0(D_0016F8E4[0]);
        return r;
    }
    func_0011D5D8(D_001A3E88);
    func_00126BC0(D_0016F8E4[0]);
    return 0x80000000;
}
