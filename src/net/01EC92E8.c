/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0xF8];
    s32 fF8;
    s32 fFC;
    s32 f100;
    char _p104[0x4];
    s32 f108;
    s32 f10C;
};
struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
};

void func_01ECCEC8();
extern Type1 *D_00167F38;

s32 func_01EC92E8(Type2 *arg0) {
    func_01ECCEC8();
    D_00167F38->fF8 = (s32) arg0->f0;
    D_00167F38->fFC = (s32) arg0->f4;
    D_00167F38->f100 = (s32) arg0->f8;
    D_00167F38->f108 = (s32) arg0->fC;
    D_00167F38->f10C = (s32) arg0->f10;
    return 0;
}
