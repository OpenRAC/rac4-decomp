#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;
struct Type3 {
    char _p0[0x4];
    s32 f4;
};
struct Type2 {
    char _p0[0x10];
    Type3 *f10;
};
struct Type1 {
    char _p0[0x4];
    Type2 *f4;
};
/* Return an observed field or field-derived value through the documented pointer offsets. */

s32 func_L00_0052D728(Type1 *arg0) {
    return arg0->f4->f10->f4;
}
