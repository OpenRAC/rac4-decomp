/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct { char _p0[8]; void (*f8)(Type1 *, s32); } Type2;
struct Type1 { Type2 *vt; };
extern Type1 *D_0016E5CC;
void func_01EFF9D4(void) {
    if (D_0016E5CC != NULL) {
        D_0016E5CC->vt->f8(D_0016E5CC, 3);
        D_0016E5CC = NULL;
    }
}
