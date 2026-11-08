/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

s32 func_01EE3A18(s32, void *);
extern s32 D_0019C880[];
extern s32 D_0019C888[];
extern s32 D_0019C890[];
extern s32 D_0019C898[];

void func_01EF3E48(s32 arg0, Type1 *arg1, s32 arg2) {
    arg1->f0 = func_01EE3A18(arg2, D_0019C880);
    arg1->f4 = func_01EE3A18(arg2, D_0019C888);
    arg1->f8 = func_01EE3A18(arg2, D_0019C890);
    arg1->fC = func_01EE3A18(arg2, D_0019C898);
}
