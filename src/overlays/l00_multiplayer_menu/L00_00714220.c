#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x80];
    s32 (*f80)();
};
struct Type1 {
    char _p0[0x58];
    Type2 *f58;
};


void func_L00_00714220(Type1 *arg0) {
    arg0->f58->f80(arg0, 0, 0);
}
