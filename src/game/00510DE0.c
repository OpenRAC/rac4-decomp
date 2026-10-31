#include "common.h"

extern void *func_00488C98(s32);

// Call the function whose address is the first word of the pointer returned by func_00488C98 with arg0; return 0 when arg0 is 0.
s32 func_00510DE0(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return ((s32 (*)(s32))(*(u32 *)func_00488C98(arg0)))(arg0);
}
