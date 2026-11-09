/* Not matching yet: BYTES 12/1980 (tools/try_func.py func_L00_0053F170 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
void func_L00_0053D918(u64 *block, s32 key, s32 mode);

#define c2l(c, l) (l = ((u64)(*((c)++))), \
                   l |= ((u64)(*((c)++))) << 8, \
                   l |= ((u64)(*((c)++))) << 16, \
                   l |= ((u64)(*((c)++))) << 24)

#define l2c(l, c) (*((c)++) = (u8)(((l)) & 0xff), \
                   *((c)++) = (u8)(((l) >> 8) & 0xff), \
                   *((c)++) = (u8)(((l) >> 16) & 0xff), \
                   *((c)++) = (u8)(((l) >> 24) & 0xff))

#define c2ln(c, l1, l2, n) { \
    c += n; \
    l1 = l2 = 0; \
    switch (n) { \
    case 8: l2 = ((u64)(*(--(c)))) << 24; \
    case 7: l2 |= ((u64)(*(--(c)))) << 16; \
    case 6: l2 |= ((u64)(*(--(c)))) << 8; \
    case 5: l2 |= ((u64)(*(--(c)))); \
    case 4: l1 = ((u64)(*(--(c)))) << 24; \
    case 3: l1 |= ((u64)(*(--(c)))) << 16; \
    case 2: l1 |= ((u64)(*(--(c)))) << 8; \
    case 1: l1 |= ((u64)(*(--(c)))); \
    } \
}

#define l2cn(l1, l2, c, n) { \
    c += n; \
    switch (n) { \
    case 8: *(--(c)) = (u8)(((l2) >> 24) & 0xff); \
    case 7: *(--(c)) = (u8)(((l2) >> 16) & 0xff); \
    case 6: *(--(c)) = (u8)(((l2) >> 8) & 0xff); \
    case 5: *(--(c)) = (u8)(((l2)) & 0xff); \
    case 4: *(--(c)) = (u8)(((l1) >> 24) & 0xff); \
    case 3: *(--(c)) = (u8)(((l1) >> 16) & 0xff); \
    case 2: *(--(c)) = (u8)(((l1) >> 8) & 0xff); \
    case 1: *(--(c)) = (u8)(((l1)) & 0xff); \
    } \
}

/* CBC-mode block cipher over a buffer: encrypts (enc != 0) or decrypts, updating the IV. */
void func_L00_0053F170(void *input, void *output, s64 length, s32 schedule, void *ivec, s32 enc) {
    u64 tin0, tin1;
    u64 tout0, tout1, xor0, xor1;
    s64 l = length;
    u64 tin[2];
    u8 *iv;
    u8 *in = (u8 *)input;
    u8 *out = (u8 *)output;

    iv = (u8 *)ivec;
    if (enc) {
        c2l(iv, tout0);
        c2l(iv, tout1);
        for (l -= 8; l >= 0; l -= 8) {
            c2l(in, tin0);
            c2l(in, tin1);
            tin0 ^= tout0;
            tin1 ^= tout1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L00_0053D918(tin, schedule, 1);
            tout0 = tin[0];
            l2c(tout0, out);
            tout1 = tin[1];
            l2c(tout1, out);
        }
        if (l != -8) {
            c2ln(in, tin0, tin1, l + 8);
            tin0 ^= tout0;
            tin1 ^= tout1;
            tin[0] = tin0;
            tin[1] = tin1;
            func_L00_0053D918(tin, schedule, 1);
            tout0 = tin[0];
            l2c(tout0, out);
            tout1 = tin[1];
            l2c(tout1, out);
        }
        iv = (u8 *)ivec;
        l2c(tout0, iv);
        l2c(tout1, iv);
    } else {
        c2l(iv, xor0);
        c2l(iv, xor1);
        for (l -= 8; l >= 0; l -= 8) {
            c2l(in, tin0);
            tin[0] = tin0;
            c2l(in, tin1);
            tin[1] = tin1;
            func_L00_0053D918(tin, schedule, 0);
            tout0 = tin[0] ^ xor0;
            tout1 = tin[1] ^ xor1;
            l2c(tout0, out);
            l2c(tout1, out);
            xor0 = tin0;
            xor1 = tin1;
        }
        if (l != -8) {
            c2l(in, tin0);
            tin[0] = tin0;
            c2l(in, tin1);
            tin[1] = tin1;
            func_L00_0053D918(tin, schedule, 0);
            tout0 = tin[0] ^ xor0;
            tout1 = tin[1] ^ xor1;
            l2cn(tout0, tout1, out, l + 8);
            xor0 = tin0;
            xor1 = tin1;
        }
        iv = (u8 *)ivec;
        l2c(xor0, iv);
        l2c(xor1, iv);
    }
    tin0 = tin1 = tout0 = tout1 = xor0 = xor1 = 0;
    tin[0] = tin[1] = 0;
}
