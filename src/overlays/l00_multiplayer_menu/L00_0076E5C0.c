#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};
/* Return an observed field or field-derived value through the documented pointer offsets. */

s32 func_L00_0076E5C0(Type1 *arg0) {
    return arg0->f4 & 0xFFF;
}
