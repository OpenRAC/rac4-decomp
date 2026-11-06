/* Read the object word at +0xAC and forward it to the observed overlay helper. */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xAC];
    s32 fAC;
};

s32 func_L01_0056B5B0(s32);

void func_L01_003EEA00(Type1 *arg0) {
    func_L01_0056B5B0(arg0->fAC);
}
