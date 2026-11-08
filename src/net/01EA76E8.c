/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0xC];
    s32 (*fC)();
};
struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
};

s32 func_01EA8908(void *);
s32 func_01EA8928();
extern Type1 *D_00167F34;

void func_01EA76E8(Type2 *arg0) {
    if (func_01EA8928() != 0) {
        D_00167F34->fC(arg0->f8);
        arg0->f4 = 0;
        arg0->f0 = 0;
        func_01EA8908(arg0);
    }
}
