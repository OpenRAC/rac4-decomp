/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x30C4];
    s32 f30C4;
};

void func_01F0435C(s32, s32, s32);
void func_01F0C090(void *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

void func_01EEFA80(s32 arg0, s32 arg1) {
    Type1 *p;
    if (D_0016E430 == NULL) {
        func_01F0C090(D_0019C400, 0x6AD);
    }
    p = D_0016E430;
    if (p->f30C4 == 0) {
        func_01F0C090(D_0019C400, 0x6AE);
    }
    p = D_0016E430;
    func_01F0435C(p->f30C4, arg0, arg1);
}
