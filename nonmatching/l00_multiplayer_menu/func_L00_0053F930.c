/* Not matching yet: BYTES 18/2004 (tools/try_func.py func_L00_0053F930 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_0053EE08(unsigned long *block, s32 key1, s32 key2, s32 key3);
extern void func_L00_0053EFB8(unsigned long *block, s32 key1, s32 key2, s32 key3);

#define LD4(c, l) (l = ((unsigned long)(*((c)++))), \
                   l |= ((unsigned long)(*((c)++))) << 8L, \
                   l |= ((unsigned long)(*((c)++))) << 16L, \
                   l |= ((unsigned long)(*((c)++))) << 24L)

#define LDN(c, l1, l2, n) { \
    c += n; \
    l1 = l2 = 0; \
    switch (n) { \
    case 8: l2 = ((unsigned long)(*(--(c)))) << 24L; \
    case 7: l2 |= ((unsigned long)(*(--(c)))) << 16L; \
    case 6: l2 |= ((unsigned long)(*(--(c)))) << 8L; \
    case 5: l2 |= ((unsigned long)(*(--(c)))); \
    case 4: l1 = ((unsigned long)(*(--(c)))) << 24L; \
    case 3: l1 |= ((unsigned long)(*(--(c)))) << 16L; \
    case 2: l1 |= ((unsigned long)(*(--(c)))) << 8L; \
    case 1: l1 |= ((unsigned long)(*(--(c)))); \
    } \
}

#define ST4(l, c) (*((c)++) = (unsigned char)(((l)) & 0xff), \
                   *((c)++) = (unsigned char)(((l) >> 8L) & 0xff), \
                   *((c)++) = (unsigned char)(((l) >> 16L) & 0xff), \
                   *((c)++) = (unsigned char)(((l) >> 24L) & 0xff))

#define STN(l1, l2, c, n) { \
    c += n; \
    switch (n) { \
    case 8: *(--(c)) = (unsigned char)(((l2) >> 24L) & 0xff); \
    case 7: *(--(c)) = (unsigned char)(((l2) >> 16L) & 0xff); \
    case 6: *(--(c)) = (unsigned char)(((l2) >> 8L) & 0xff); \
    case 5: *(--(c)) = (unsigned char)(((l2)) & 0xff); \
    case 4: *(--(c)) = (unsigned char)(((l1) >> 24L) & 0xff); \
    case 3: *(--(c)) = (unsigned char)(((l1) >> 16L) & 0xff); \
    case 2: *(--(c)) = (unsigned char)(((l1) >> 8L) & 0xff); \
    case 1: *(--(c)) = (unsigned char)(((l1)) & 0xff); \
    } \
}

void func_L00_0053F930(unsigned char *input, unsigned char *output, long length,
                       s32 ks1, s32 ks2, s32 ks3, unsigned char *ivec, s32 enc) {
    unsigned long tin0, tin1;
    unsigned long tout0, tout1, xor0, xor1;
    unsigned char *in;
    unsigned char *out;
    long l = length;
    unsigned long tin[2];
    unsigned char *iv;

    in = input;
    out = output;
    iv = ivec;

    if (enc) {
        LD4(iv, tout0);
        LD4(iv, tout1);
        for (l -= 8; l >= 0; l -= 8) {
            LD4(in, tin0);
            LD4(in, tin1);
            tin0 ^= tout0;
            tin1 ^= tout1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L00_0053EE08(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            ST4(tout0, out);
            ST4(tout1, out);
        }
        if (l != -8) {
            LDN(in, tin0, tin1, l + 8);
            tin0 ^= tout0;
            tin1 ^= tout1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L00_0053EE08(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            ST4(tout0, out);
            ST4(tout1, out);
        }
        iv = ivec;
        ST4(tout0, iv);
        ST4(tout1, iv);
    } else {
        unsigned long t0, t1;

        LD4(iv, xor0);
        LD4(iv, xor1);
        for (l -= 8; l >= 0; l -= 8) {
            LD4(in, tin0);
            LD4(in, tin1);
            t0 = tin0;
            t1 = tin1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L00_0053EFB8(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            tout0 ^= xor0;
            tout1 ^= xor1;
            ST4(tout0, out);
            ST4(tout1, out);
            xor0 = t0;
            xor1 = t1;
        }
        if (l != -8) {
            LD4(in, tin0);
            LD4(in, tin1);
            t0 = tin0;
            t1 = tin1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L00_0053EFB8(tin, ks1, ks2, ks3);
            tout0 = tin[0];
            tout1 = tin[1];
            tout0 ^= xor0;
            tout1 ^= xor1;
            STN(tout0, tout1, out, l + 8);
            xor0 = t0;
            xor1 = t1;
        }
        iv = ivec;
        ST4(xor0, iv);
        ST4(xor1, iv);
    }
    tin0 = tin1 = tout0 = tout1 = xor0 = xor1 = 0;
    tin[0] = tin[1] = 0;
}
