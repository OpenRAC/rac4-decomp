#include "common.h"

extern void *func_004FBF90(s32, s32);
// Copies a 24-byte unaligned record from the pointer func_004FBF90 returns into arg0.
typedef struct {
    u64 a;
    u64 b;
    u64 c;
} __attribute__((packed)) Rec24;

void func_00498C98(Rec24 *arg0) {
    Rec24 *src;
    src = func_004FBF90(*(s32 *)arg0, *(s32 *)((u8 *)arg0 + 4));
    *arg0 = *src;
}
