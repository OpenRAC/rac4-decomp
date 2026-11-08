/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC];
    s32 fC;
};

s32 *func_0011A1A0();
s32 func_L00_005669C0();
extern s32 D_004A9BA8;

s32 func_L00_00566BA0(Type1 *arg0, s32 arg1) {
    arg0->fC = arg1;
    if (D_004A9BA8 != 0) {
        *func_0011A1A0() = arg1;
    }
    func_L00_005669C0();
    return (arg1 == 0) ? 0 : -1;
}
