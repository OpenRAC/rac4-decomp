/* cflags: @ee29 -O2 -G0 */
#include "common.h"

void func_L00_0053E428(u64 *block, s32 key, s32 mode);

#define PERM(a, b, n, m) t = ((a >> n) ^ b) & m; b ^= t; a ^= t << n

void func_L00_0053EE08(u64 *block, s32 key1, s32 key2, s32 key3) {
    u64 l, r, t;

    l = block[1];
    r = block[0];
    PERM(l, r, 4, 0x0F0F0F0F);
    PERM(r, l, 16, 0xFFFF);
    PERM(l, r, 2, 0x33333333);
    PERM(r, l, 8, 0x00FF00FF);
    PERM(l, r, 1, 0x55555555);
    block[0] = r;
    block[1] = l;
    func_L00_0053E428(block, key1, 1);
    func_L00_0053E428(block, key2, 0);
    func_L00_0053E428(block, key3, 1);
    l = block[1];
    r = block[0];
    PERM(l, r, 1, 0x55555555);
    PERM(r, l, 8, 0x00FF00FF);
    PERM(l, r, 2, 0x33333333);
    PERM(r, l, 16, 0xFFFF);
    PERM(l, r, 4, 0x0F0F0F0F);
    block[0] = r;
    block[1] = l;
}
