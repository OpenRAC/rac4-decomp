#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x268];
    s32 f2E0;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};
/* Return an observed field or field-derived value through the documented pointer offsets. */

s32 func_L41_003BD8D0(Type1 *arg0) {
    return arg0->fAC->f2E0;
}
