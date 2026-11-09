/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad[0x1C];
    s32 unk1C;
} Type1;

extern Type1 *func_00517808(void);
s32 func_L00_00528B80(u8 *key);
s32 func_L00_00528BC8(u8 *key);
extern s32 D_004A1AB0[];
extern const unsigned long D_004AE830[][64];

#define PERM_OP(a, b, t, n, m) ((t) = ((((a) >> (n)) ^ (b)) & (m)), (b) ^= (t), (a) ^= ((t) << (n)))
#define HPERM_OP(a, t, n, m) ((t) = ((((a) << (16 - (n))) ^ (a)) & (m)), (a) = (a) ^ (t) ^ (t >> (16 - (n))))
#define ROTATE(a, n) (((a) >> (n)) + ((a) << (32 - (n))))

s32 func_L00_00528C38(u8 *key, unsigned long *k) {
    unsigned long c, d, t, s, t2;
    u8 *in;
    s32 i;

    if (func_00517808()->unk1C) {
        if (!func_L00_00528B80(key)) {
            return -1;
        }
        if (func_L00_00528BC8(key)) {
            return -2;
        }
    }

    in = key;
    c = (unsigned long)in[0];
    c |= (unsigned long)in[1] << 8;
    c |= (unsigned long)in[2] << 16;
    c |= (unsigned long)in[3] << 24;
    d = (unsigned long)in[4];
    d |= (unsigned long)in[5] << 8;
    d |= (unsigned long)in[6] << 16;
    d |= (unsigned long)in[7] << 24;

    PERM_OP(d, c, t, 4, 0x0f0f0f0fUL);
    HPERM_OP(c, t, -2, 0xcccc0000UL);
    HPERM_OP(d, t, -2, 0xcccc0000UL);
    PERM_OP(d, c, t, 1, 0x55555555UL);
    PERM_OP(c, d, t, 8, 0x00ff00ffUL);
    PERM_OP(d, c, t, 1, 0x55555555UL);
    d = (((d & 0x000000ffUL) << 16) | (d & 0x0000ff00UL) |
         ((d & 0x00ff0000UL) >> 16) | ((c & 0xf0000000UL) >> 4));
    c &= 0x0fffffffUL;

    for (i = 0; i < 16; i++) {
        if (D_004A1AB0[i]) {
            c = ((c >> 2) | (c << 26));
            d = ((d >> 2) | (d << 26));
        } else {
            c = ((c >> 1) | (c << 27));
            d = ((d >> 1) | (d << 27));
        }
        c &= 0x0fffffffUL;
        d &= 0x0fffffffUL;
        s = D_004AE830[0][(c) & 0x3f] |
            D_004AE830[1][((c >> 6) & 0x03) | ((c >> 7) & 0x3c)] |
            D_004AE830[2][((c >> 13) & 0x0f) | ((c >> 14) & 0x30)] |
            D_004AE830[3][((c >> 20) & 0x01) | ((c >> 21) & 0x06) | ((c >> 22) & 0x38)];
        t = D_004AE830[4][(d) & 0x3f] |
            D_004AE830[5][((d >> 7) & 0x03) | ((d >> 8) & 0x3c)] |
            D_004AE830[6][(d >> 15) & 0x3f] |
            D_004AE830[7][((d >> 21) & 0x0f) | ((d >> 22) & 0x30)];

        t2 = ((t << 16) | (s & 0x0000ffffUL)) & 0xffffffffUL;
        *(k++) = ROTATE(t2, 30) & 0xffffffffUL;
        t2 = ((s >> 16) | (t & 0xffff0000UL));
        *(k++) = ROTATE(t2, 26) & 0xffffffffUL;
    }
    return 0;
}
