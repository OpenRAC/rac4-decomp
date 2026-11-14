#include "common.h"

typedef struct Type1 {
    u8 pad0[0x68];
    s32 f68;
    void *f6C[1];
} Type1;

extern s32 func_0069CC48(void *arg0, s32 arg1, s32 arg2);
extern void func_L00_007162A0(void *arg0);

// calls func_0069CC48 on each item of the list at arg0 and returns 1 if any call returned nonzero
s32 func_L00_007160C8(Type1 *arg0, s32 arg1, s32 arg2) {
    s32 result = 0;
    s32 i;
    for (i = 0; i < arg0->f68; i++) {
        result |= func_0069CC48(arg0->f6C[i], arg1, arg2) != 0;
    }
    if (result == 1) {
        func_L00_007162A0(arg0);
    }
    return result;
}
