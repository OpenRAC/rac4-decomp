/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x1C];
    s32 f1C;
    char _p20[0x3F8];
    s32 f418;
    char _p41C[0x4];
    s32 f420;
};

s32 func_0011A370(s32, s32, u32);
s32 func_0011EAA0(void *, s32, void *);
extern s32 D_00199F28[];
extern s32 D_0019A310[];

u32 func_01EE05B8(Type1 *arg0, s32 arg1, u32 arg2) {
    if ((u32) (arg0->f418 - arg0->f1C) < arg2) {
        func_0011EAA0(D_00199F28, 0x470, D_0019A310);
    }
    func_0011A370(arg0->f420 + arg0->f1C, arg1, arg2);
    arg0->f1C = (s32) (arg0->f1C + arg2);
    return arg2;
}
