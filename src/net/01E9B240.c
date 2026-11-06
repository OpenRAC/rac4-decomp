/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
typedef struct { u64 v; } __attribute__((packed)) Unal8;
// Copies 16 bytes from arg0+0x24 to arg1 (unaligned), two doublewords, returns 0.
s32 func_01E9B240(void *arg0, void *arg1) {
    u64 a = ((Unal8 *)((u8 *)arg0 + 0x24))->v;
    u64 b = ((Unal8 *)((u8 *)arg0 + 0x2C))->v;
    ((Unal8 *)arg1)->v = a;
    ((Unal8 *)((u8 *)arg1 + 8))->v = b;
    return 0;
}
