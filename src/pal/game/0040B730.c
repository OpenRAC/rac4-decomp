/* cflags: -O1 */
#include "common.h"

typedef struct __attribute__((packed)) {
    u64 f0;
} Type1;

/* Copies an unaligned eight-byte field and returns success. */
s32 func_0040B730(char *a, Type1 *b)
{
    b->f0 = ((Type1 *)(a + 12))->f0;
    return 0;
}
