#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x14];
    s32 f14;
};
/* Return an observed field or field-derived value through the documented pointer offsets. */

s32 func_L00_004F7250(Type1 *arg0) {
    return arg0->f14 & 1;
}
