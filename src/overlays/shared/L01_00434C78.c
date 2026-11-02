#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xAC];
    s32 fAC;
};

s32 func_005589E0(void *, s32, void *);
extern s32 D_003B1ED0[];
extern s32 D_00222B28[];
#define D_003CFC88 (D_003B1ED0[0])
#define D_221288 (D_00222B28[0])

void func_L01_00434C78(Type1 *arg0) {
    func_005589E0(&D_221288, arg0->fAC + 0x50, &D_003CFC88);
}
