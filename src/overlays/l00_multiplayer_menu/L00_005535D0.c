/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    u64 f0;
    s32 f8;
    s16 f10;
    char _pE[0x6];
    u8 f14;
    char _p15[1];
    u8 f16;
};

extern void func_L00_00553638(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_L00_00553678(Type1 *arg0, s32 arg1, s64 arg2);

void func_L00_005535D0(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4, s32 arg5, s32 arg6) {
    func_L00_00553638(arg0, arg1, arg2, arg5);
    func_L00_00553678(arg0, arg3, arg4);
    arg0->f16 |= arg6;
}
