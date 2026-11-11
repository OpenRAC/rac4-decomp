/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_L11_003C5088(void *arg0) {
    u8 ff = 0xFF;
    s32 one = 1;

    (*(u8 *)((u8 *)arg0 + 0x20)) = one;
    (*(u8 *)((u8 *)arg0 + 0x30)) = ff;
    return one;
}
