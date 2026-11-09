/* Not matching yet: BYTES 65/472 (tools/try_func.py func_004DCCB8 --diff). Not part of the build. */
#include "common.h"

extern void func_004E7990(s32 reg, u64 value, s32 retained_mode);
extern s32 D_001D3F40[];
extern s16 D_00206A40[];
extern u8 *D_00221E20;

void func_004DCCB8(void)
{
    s32 n;
    s32 w;
    s32 x;
    s32 y;
    s32 d;
    s32 i;
    s32 c;
    u64 lo;
    u64 hi;
    u64 *q;
    u64 *r;
    u8 *p;

    n = D_001D3F40[0] >> 5;
    func_004E7990(0x42, 0x64, 0);
    w = n + 5;
    *(s32 *)(D_00221E20 + 0x0) = w | 0x10000000;
    *(s32 *)(D_00221E20 + 0x4) = 0;
    *(s32 *)(D_00221E20 + 0x8) = 0;
    *(s32 *)(D_00221E20 + 0xC) = w | 0x50000000;
    p = D_00221E20;
    q = (u64 *)(p + 0x10);
    D_00221E20 = (u8 *)q;
    ((u64 *)p)[2] = 0x1000000000000001ULL;
    q[1] = 0xE;
    q[2] = 0x35001;
    q[3] = 0x47;
    q[4] = 0x2400000000008001ULL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = 0x80808080;
    q[8] = (u64)(n | 0x8000) | 0x2400000000000000ULL;
    q[9] = 0x44;
    c = 0x8000;
    x = D_001D3F40[2] * 16 + c - D_00206A40[0xA8] * 8 - D_001D3F40[0] * 8;
    y = D_001D3F40[3] * 16 + c - D_00206A40[0xA9] * 8;
    d = D_001D3F40[1] * 8;
    hi = y + d;
    lo = y - d;
    i = 0;
    if (n > 0) {
        r = (u64 *)(p + 0x60);
        do {
            *r++ = (x + i * 0x200) | (lo << 16);
            *r++ = (x + i * 0x200 + 0x200) | (hi << 16);
            i++;
        } while (i < n);
    }
    D_00221E20 += n * 16 + 0x50;
}
