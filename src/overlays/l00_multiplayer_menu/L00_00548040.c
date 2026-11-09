/* cflags: -G0 */
#include "common.h"

void func_00551E10(s32, s32, s8 *);
extern s8 D_004771A8[];

void func_L00_00548040(s32 arg0, s32 arg1, s8 *arg2) {
    if (arg2 == NULL) {
        arg2 = (D_004771A8[0] == 0) ? NULL : D_004771A8;
    }
    func_00551E10(arg0, arg1, arg2);
}
