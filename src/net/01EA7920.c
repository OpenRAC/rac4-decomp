/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Pair { s32 a; s32 b; } Pair;
extern s32 D_00167F34[];
extern s32 func_01EA8928(const void *handle);
extern void func_01EA89E0(s32, s32, s32);

/* Pass the request to the object held in D_00167F34 and report the result through arg4. */
s32 func_01EA7920(u8 *arg0, Pair arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s32 ret;

    if (((s32 (*)(Pair))(*(s32 *)((u8 *)D_00167F34[0] + 0x54)))(arg1) != 0) {
        return 2;
    }
    *arg4 = 0;
    if (arg3 == 0) {
        return 2;
    }
    if (func_01EA8928(arg0) == 0) {
        return 2;
    }
    if (*(s32 *)(arg0 + 0xC) != 1) {
        return 0xC355;
    }
    ret = ((s32 (*)(s32, Pair, s32, s32, s32 *))(*(s32 *)((u8 *)D_00167F34[0] + 0x1C)))(*(s32 *)(arg0 + 8), arg1, arg2, arg3, arg4);
    if (ret != 0) {
        return ret;
    }
    func_01EA89E0(*arg4, 0, 0x1C);
    return 0;
}
