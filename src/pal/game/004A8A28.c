#include "common.h"

extern s32 func_00549010(s32);
extern void *func_0054A290(s32, s32);
extern void func_004A8DC0(s32, s32);
typedef struct Type1 {
    char pad[0x98];
    s32 f98;
    char pad9C[0x1c];
} Type1;
extern Type1 D_00308208[];
/* Mark the indexed entry after validating the requested object. */
s32 func_004A8A28(s32 index, s32 value)
{
    if (func_00549010(value) && *((u8 *)func_0054A290(value, 0) + 0x28)) {
        func_004A8DC0(index, value);
        D_00308208[index].f98 |= 4;
        return 1;
    }
    return 0;
}
