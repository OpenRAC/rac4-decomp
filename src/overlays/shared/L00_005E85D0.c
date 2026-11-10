/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern char D_00222290[];
extern void func_L00_005E8490(s32 a0, s32 a1, s32 a2, s32 a3, u128 v);

/* Forward the four arguments plus the 16-byte snapshot of the global record. */
void func_L00_005E85D0(s32 a0, s32 a1, s32 a2, s32 a3)
{
    u128 v = *(u128 *)D_00222290;

    func_L00_005E8490(a0, a1, a2, a3, v);
}
