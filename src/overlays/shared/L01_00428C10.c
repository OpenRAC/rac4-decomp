#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x44];
    s32 f44;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};
/* Update the observed field through the documented pointer offsets. */

void func_L01_00428C10(Type1 *arg0, s32 arg1) {
    arg0->fAC->f44 = arg1;
}
