#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xAC];
    s32 fAC;
};
/* Return an observed field or field-derived value through the documented pointer offsets. */

s32 func_L01_00492728(Type1 *arg0) {
    return arg0->fAC + 0x440;
}
