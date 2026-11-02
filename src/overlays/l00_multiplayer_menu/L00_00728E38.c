#include "common.h"

// Call func_L00_0071B690, then method +0x1C of the object at +0x268.

typedef struct Type3 Type3;

typedef struct Type2 {
    char _p0[0x1C];
    void (*f1C)(Type3 *arg0);
} Type2;

struct Type3 {
    char _p0[0x58];
    Type2 *f58;
};

typedef struct Type1 {
    char _p0[0x2870];
    Type3 *f268;
} Type1;

extern void func_L00_0071B690(Type1 *arg0);

void func_L00_00728E38(Type1 *arg0) {
    Type3 *o;

    func_L00_0071B690(arg0);
    o = arg0->f268;
    o->f58->f1C(o);
}
