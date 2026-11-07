/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xC];
    s32 f10;
};

extern s32 (*D_00169D44)(s32, s32);
extern s32 D_00169D4C[];

void func_01ED5F90(Type1 *arg0) {
    D_00169D4C[0] = 1;
    if (D_00169D44 != NULL) {
        D_00169D44(arg0->f0, arg0->f10);
    }
    D_00169D44 = NULL;
}
