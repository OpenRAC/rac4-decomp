/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x28];
    s32 (*f28)();
};
struct Type1 {
    char _p0[0x8];
    s32 f8;
    char _pC[0x9C];
    s32 fA8;
    char _pAC[0x4];
    Type2 *fB0;
};

void func_01EF3BBC(Type1 *arg0, s32 arg1) {
    s32 var_s2;

    var_s2 = 0;
    if (arg0->fB0->f28() != 0) {
        var_s2 = (arg0->fA8 == 0) ? (arg1 != 0) : 0;
    }
    arg0->f8 = var_s2;
}
