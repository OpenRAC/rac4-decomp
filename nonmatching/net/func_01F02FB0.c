/* Not matching yet: SIZE ours 184 / retail 188 (tools/try_func.py func_01F02FB0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x78];
    s32 f78;
    char _p7C[0x3C];
    s32 fB8;
    char _pBC[0x10];
    s32 fCC;
    char *fD0;
    char _pD4[0x10];
    s32 fE4;
    s32 fE8;
    char _pEC[0x8C];
    s32 f178;
    s32 f17C;
};

extern char D_0019DC20[];
extern void func_01F0C090(char *arg0, s32 arg1);
extern void func_01F02B38(Type1 *arg0, s32 **arg1);

s32 func_01F02FB0(Type1 *arg0) {
    s32 *var_v1;
    s32 var_a1;

    var_v1 = 0;
    if (arg0->f178 != 0 && arg0->f17C == 0) {
        return arg0->f78;
    }
    if (arg0->fE4 == -1) {
        var_a1 = arg0->fE8;
        if ((arg0->fB8 < var_a1) || (var_a1 < 0)) {
            func_01F0C090(D_0019DC20, 0x643);
            return 0;
        }
        return *(s32 *)((var_a1 << 5) + arg0->fD0 + 8);
    }
    if (arg0->fCC == 0) {
        return 0;
    }
    func_01F02B38(arg0, &var_v1);
    if (var_v1 != 0) {
        return var_v1[2];
    }
    func_01F0C090(D_0019DC20, 0x658);
    return 0;
}
