#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x40];
    s16 f48;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};
/* Update the observed field through the documented pointer offsets. */

void func_L05_003EAB00(Type1 *arg0, s16 arg1) {
    arg0->fAC->f48 = arg1;
}
