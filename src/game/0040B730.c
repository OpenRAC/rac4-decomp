#include "common.h"

typedef struct __attribute__((packed)) {
    u64 v;
} Unaligned64;

/* Copies the possibly unaligned doubleword at src + 0xC to dst (ldl/ldr, sdl/sdr) and returns 0. */
s32 func_0040B730(u8 *src, u8 *dst) {
    ((Unaligned64 *)dst)->v = ((Unaligned64 *)(src + 0xC))->v;
    return 0;
}
