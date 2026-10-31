#include "common.h"

/* Stores the four initial state words and clears the first two 64-bit words of the block at arg0. */
void func_01EF0D44(void *arg0) {
    u64 w0 = 0x67452301;
    u64 w1 = 0xEFCDAB89;
    u64 w2 = 0x98BADCFE;
    u64 w3 = 0x10325476;
    *(u64 *)((u8 *)arg0 + 0x10) = w0;
    *(u64 *)((u8 *)arg0 + 0x28) = w3;
    *(u64 *)((u8 *)arg0 + 0x18) = w1;
    *(u64 *)((u8 *)arg0 + 0x20) = w2;
    *(u64 *)((u8 *)arg0 + 0x8) = 0;
    *(u64 *)((u8 *)arg0 + 0x0) = 0;
}
