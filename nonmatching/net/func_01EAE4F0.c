/* Not matching yet: SIZE ours 140 / retail 136 (tools/try_func.py func_01EAE4F0 --diff). Not part of the build. */
#include "common.h"

// Encrypt `len` bytes of `buf` in place with the generator state in `p`.
void func_01EAE4F0(u8 *p, u8 *buf, s32 len) {
    u8 *s = p + 0xC;
    u8 i = *(u8 *)(p + 0x4);
    u8 j = *(u8 *)(p + 0x8);
    u8 x;
    u8 y;
    u8 k;

    *(u32 *)p += len;
    do {
        i += 5;
        x = s[i];
        j += x;
        y = s[j];
        s[j] = x;
        s[i] = y;
        k = s[(u8)(x + y)];
        *buf ^= k;
        buf++;
        j += s[k];
        len--;
    } while (len != 0);
    *(u8 *)(p + 0x4) = i;
    *(u8 *)(p + 0x8) = j;
}
