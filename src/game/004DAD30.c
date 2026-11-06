#include "common.h"

extern void func_004A1358(void *), func_004A1310(void *), func_00497980(s32);
typedef struct Type1 {
    char pad[0x50];
    s32 f50, f54;
} Type1;
extern Type1 D_00322EA4[];
typedef struct Type2 {
    s32 f0;
    u32 f4;
} Type2;
extern Type2 D_00321B98[];
void func_004DAD30(s32 direction)
{
    if (D_00322EA4[0].f50 >= 2) {
        s32 previous = D_00322EA4[0].f54;
        if (direction)
            func_004A1358(D_00322EA4);
        else
            func_004A1310(D_00322EA4);
        if (previous == D_00322EA4[0].f54)
            func_00497980(4);
        else
            func_00497980(0);
        D_00321B98[0].f4 |= 2;
        return;
    }
    func_00497980(4);
}
