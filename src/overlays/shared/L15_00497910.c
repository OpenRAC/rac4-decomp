#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0xF0];
    s32 fF0;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};

s16 func_L15_00497910(Type1 *arg0) {
    return arg0->fAC->fF0;
}
