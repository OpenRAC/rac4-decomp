#include "common.h"
typedef int s128 __attribute__((mode(TI)));
extern s32 func_0047C378(s128, s32);
s32 func_L06_004C0D58(void *arg0, s128 *arg1) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0xAC);
    if (state[0xA] == 0) return 0;
    return func_0047C378(*arg1, *(s32 *)state) != 0;
}