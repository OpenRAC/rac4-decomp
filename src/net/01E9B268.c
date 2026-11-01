/* cflags: -fno-schedule-insns */
#include "common.h"

typedef struct { u64 f0; u64 f8; } __attribute__((packed)) Type1;
typedef struct { u8 f0[0x34]; u64 f34; u64 f3C; } __attribute__((packed)) Type2;
/* Copies sixteen bytes into the destination at offset 0x34. */
s32 func_01E9B268(Type2 *dst, const Type1 *src) {
    u64 first = src->f0;
    u64 second = src->f8;
    dst->f34 = first;
    dst->f3C = second;
    return 0;
}
