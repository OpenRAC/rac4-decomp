#include "common.h"

typedef struct {
    u8 f0;
    u8 f1;
    u8 b;
    u8 d;
    u32 f;
} Type3;

/* Stores the word of the packet at arg2 into entry b (0x18 bytes each) of the table at 0x188, when the table is set. */
s32 func_01EBA450(u8 *arg0, s32 unused, Type3 *arg2) {
    Type3 packet = *arg2;
    char *entries = *(char **)(arg0 + 0x188);
    if (entries) {
        u32 i = packet.b;
        *(u32 *)((char *)(((i << 1) + i) << 3) + (u32)entries + 0x14) = packet.f;
    }
    return 0;
}
