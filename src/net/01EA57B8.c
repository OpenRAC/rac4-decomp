/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x24];
    s32 f24;
    u8 f28[1];
};

s32 func_01EA9E28(void *, s32);
extern Type1 *D_00167EFC;

s32 func_01EA57B8(void) {
    Type1 *p = D_00167EFC;
    if (p->f24 == 0) {
        return 5;
    }
    return func_01EA9E28(p->f28, 0);
}
