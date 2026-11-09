/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern unsigned int D_004AD2C8[];
extern unsigned char D_004AD3B8[];
extern int D_004AD3F8[];

/* Hash one 64-byte block into the four-word state, byte-swapping it first on a big-endian host. */
void func_L00_0051BB50(unsigned int *state, unsigned int *block)
{
    unsigned int a, b, c, d;
    long t;
    int i, s, inc;
    unsigned int *p;
    unsigned long v;

    s = 0;
    inc = 0;
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    if (D_004AD3F8[0] != *(unsigned char *)D_004AD3F8) {
        p = block;
        for (i = 0; i < 16; i++) {
            v = *p;
            v = ((v & 0xFF00FF00) >> 8) | ((v & 0x00FF00FF) << 8);
            *p++ = (v << 16) | ((v & 0xFFFFFFFF) >> 16);
        }
    }
    for (i = 0; i < 16; i++) {
        if (!(i & 3))
            s = 7;
        else
            s += 5;
        a = a + D_004AD2C8[i] + (((c ^ d) & b) ^ d) + block[i];
        a = (a << s) | (a >> (32 - s));
        a += b;
        t = a;
        a = d;
        d = c;
        c = b;
        b = t;
    }
    for (i = 16; i < 32; i++) {
        s += inc;
        if (!(i & 3)) {
            s = 5;
            inc = 4;
        } else {
            inc++;
        }
        a = a + D_004AD2C8[i] + (((b ^ c) & d) ^ c) + block[D_004AD3B8[i]];
        a = (a << s) | (a >> (32 - s));
        a += b;
        t = a;
        a = d;
        d = c;
        c = b;
        b = t;
    }
    for (i = 32; i < 48; i++) {
        s += 7;
        if (!(i & 3))
            s = 4;
        else if (!(i & 1))
            s -= 2;
        a = a + D_004AD2C8[i] + (b ^ c ^ d) + block[D_004AD3B8[i]];
        a = (a << s) | (a >> (32 - s));
        a += b;
        t = a;
        a = d;
        d = c;
        c = b;
        b = t;
    }
    for (i = 48; i < 64; i++) {
        s += inc;
        if (!(i & 3)) {
            s = 6;
            inc = 4;
        } else {
            inc++;
        }
        a = a + D_004AD2C8[i] + ((~d | b) ^ c) + block[D_004AD3B8[i]];
        a = (a << s) | (a >> (32 - s));
        a += b;
        t = a;
        a = d;
        d = c;
        c = b;
        b = t;
    }
    a += state[0];
    b += state[1];
    c += state[2];
    d += state[3];
    state[0] = a;
    state[1] = b;
    state[2] = c;
    state[3] = d;
}
