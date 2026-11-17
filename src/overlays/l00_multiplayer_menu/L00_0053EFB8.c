/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_0053E428(u64 *data, u64 *ks, s32 enc);

/* DES-style initial permutation on the 64-bit block, three keyed passes, then the final permutation. */
void func_L00_0053EFB8(u64 *block, s32 key1, s32 key2, s32 key3) {
    u64 l, r, t;

    l = block[1];
    r = block[0];
    t = ((l >> 4) ^ r) & 0x0F0F0F0F;
    r ^= t;
    l ^= t << 4;
    t = ((r >> 16) ^ l) & 0xFFFF;
    l ^= t;
    r ^= t << 16;
    t = ((l >> 2) ^ r) & 0x33333333;
    r ^= t;
    l ^= t << 2;
    t = ((r >> 8) ^ l) & 0x00FF00FF;
    l ^= t;
    r ^= t << 8;
    t = ((l >> 1) ^ r) & 0x55555555;
    r ^= t;
    l ^= t << 1;
    block[0] = r;
    block[1] = l;
    func_L00_0053E428(block, key3, 0);
    func_L00_0053E428(block, key2, 1);
    func_L00_0053E428(block, key1, 0);
    l = block[1];
    r = block[0];
    t = ((l >> 1) ^ r) & 0x55555555;
    r ^= t;
    l ^= t << 1;
    t = ((r >> 8) ^ l) & 0x00FF00FF;
    l ^= t;
    r ^= t << 8;
    t = ((l >> 2) ^ r) & 0x33333333;
    r ^= t;
    l ^= t << 2;
    t = ((r >> 16) ^ l) & 0xFFFF;
    l ^= t;
    r ^= t << 16;
    t = ((l >> 4) ^ r) & 0x0F0F0F0F;
    r ^= t;
    l ^= t << 4;
    block[0] = r;
    block[1] = l;
}
