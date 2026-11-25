/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Pair { s32 a; s32 b; } Pair;
extern s32 D_00167F34[];
extern s32 func_01EA8928(const void *handle);
extern void func_01EA89E0(s32, s32, s32);

s32 func_01EA79F8(u8 *arg0, s32 *arg1, Pair arg2, s32 arg3) {
    s32 ret;

    ret = 2;
    if (arg1 == 0) {
        return ret;
    }
    *arg1 = 0;
    if (((s32 (*)(Pair))(*(s32 *)((u8 *)D_00167F34[0] + 0x54)))(arg2) != 0) {
        return 2;
    }
    if (func_01EA8928(arg0) == 0) {
        return 2;
    }
    if (*(s32 *)(arg0 + 0xC) != 3) {
        return 0xC355;
    }
    ret = ((s32 (*)(s32, s32 *, Pair, s32))(*(s32 *)((u8 *)D_00167F34[0] + 0x20)))(*(s32 *)(arg0 + 8), arg1, arg2, arg3);
    if (ret != 0) {
        return ret;
    }
    func_01EA89E0(0x1C, 0, 0);
    return 0;
}
