#include "common.h"

extern s32 func_00547AC8(s32);
extern void *func_00548D28(s32, s32);
void func_004A8050(s32 arg0, s32 arg1);
typedef struct Type1 {
    char pad[0x98];
    s32 f98;
    char pad9C[0x1c];
} Type1;
extern Type1 D_00308108[];
/* Mark the indexed entry after validating the requested object. */
s32 func_004A7CB8(s32 index, s32 value)
{
    if (func_00547AC8(value) && *((u8 *)func_00548D28(value, 0) + 0x28)) {
        func_004A8050(index, value);
        D_00308108[index].f98 |= 4;
        return 1;
    }
    return 0;
}
