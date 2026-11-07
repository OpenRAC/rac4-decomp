#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x58];
    void *f58;
};

void func_L00_007107F0(void *);
extern s32 D_004B7A38[];

void *func_L00_00710788(Type1 *arg0) {
    arg0->f58 = D_004B7A38;
    func_L00_007107F0(arg0);
    return arg0;
}
