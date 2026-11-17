/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

// MD5 block transform (RFC 1321), in the form of Christophe Devine's md5.c (GPL-2.0-or-later,
// THIRD_PARTY_NOTICES.md): uint32 is unsigned long, 64 bits here, hence the masks in S().
typedef unsigned long uint32;
typedef struct { uint32 total[2]; uint32 state[4]; u8 buffer[64]; } md5_context;
#define GET_UINT32(n, b, i) { (n) = ((uint32)(b)[(i)]) | ((uint32)(b)[(i) + 1] << 8) | ((uint32)(b)[(i) + 2] << 16) | ((uint32)(b)[(i) + 3] << 24); }
#define S(x, n) ((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))
#define P(a, b, c, d, x, s, t) { a += F(b, c, d) + x + t; a = S(a, s) + b; }
void func_01EF0D88(md5_context *ctx, u8 *data) {
    uint32 X[16], A, B, C, D;

    GET_UINT32(X[0], data, 0);
    GET_UINT32(X[1], data, 4);
    GET_UINT32(X[2], data, 8);
    GET_UINT32(X[3], data, 12);
    GET_UINT32(X[4], data, 16);
    GET_UINT32(X[5], data, 20);
    GET_UINT32(X[6], data, 24);
    GET_UINT32(X[7], data, 28);
    GET_UINT32(X[8], data, 32);
    GET_UINT32(X[9], data, 36);
    GET_UINT32(X[10], data, 40);
    GET_UINT32(X[11], data, 44);
    GET_UINT32(X[12], data, 48);
    GET_UINT32(X[13], data, 52);
    GET_UINT32(X[14], data, 56);
    GET_UINT32(X[15], data, 60);

    A = ctx->state[0];
    B = ctx->state[1];
    C = ctx->state[2];
    D = ctx->state[3];

#define F(x, y, z) (z ^ (x & (y ^ z)))
    P(A, B, C, D, X[0], 7, 0xD76AA478);
    P(D, A, B, C, X[1], 12, 0xE8C7B756);
    P(C, D, A, B, X[2], 17, 0x242070DB);
    P(B, C, D, A, X[3], 22, 0xC1BDCEEE);
    P(A, B, C, D, X[4], 7, 0xF57C0FAF);
    P(D, A, B, C, X[5], 12, 0x4787C62A);
    P(C, D, A, B, X[6], 17, 0xA8304613);
    P(B, C, D, A, X[7], 22, 0xFD469501);
    P(A, B, C, D, X[8], 7, 0x698098D8);
    P(D, A, B, C, X[9], 12, 0x8B44F7AF);
    P(C, D, A, B, X[10], 17, 0xFFFF5BB1);
    P(B, C, D, A, X[11], 22, 0x895CD7BE);
    P(A, B, C, D, X[12], 7, 0x6B901122);
    P(D, A, B, C, X[13], 12, 0xFD987193);
    P(C, D, A, B, X[14], 17, 0xA679438E);
    P(B, C, D, A, X[15], 22, 0x49B40821);
#undef F
#define F(x, y, z) (y ^ (z & (x ^ y)))
    P(A, B, C, D, X[1], 5, 0xF61E2562);
    P(D, A, B, C, X[6], 9, 0xC040B340);
    P(C, D, A, B, X[11], 14, 0x265E5A51);
    P(B, C, D, A, X[0], 20, 0xE9B6C7AA);
    P(A, B, C, D, X[5], 5, 0xD62F105D);
    P(D, A, B, C, X[10], 9, 0x02441453);
    P(C, D, A, B, X[15], 14, 0xD8A1E681);
    P(B, C, D, A, X[4], 20, 0xE7D3FBC8);
    P(A, B, C, D, X[9], 5, 0x21E1CDE6);
    P(D, A, B, C, X[14], 9, 0xC33707D6);
    P(C, D, A, B, X[3], 14, 0xF4D50D87);
    P(B, C, D, A, X[8], 20, 0x455A14ED);
    P(A, B, C, D, X[13], 5, 0xA9E3E905);
    P(D, A, B, C, X[2], 9, 0xFCEFA3F8);
    P(C, D, A, B, X[7], 14, 0x676F02D9);
    P(B, C, D, A, X[12], 20, 0x8D2A4C8A);
#undef F
#define F(x, y, z) (x ^ y ^ z)
    P(A, B, C, D, X[5], 4, 0xFFFA3942);
    P(D, A, B, C, X[8], 11, 0x8771F681);
    P(C, D, A, B, X[11], 16, 0x6D9D6122);
    P(B, C, D, A, X[14], 23, 0xFDE5380C);
    P(A, B, C, D, X[1], 4, 0xA4BEEA44);
    P(D, A, B, C, X[4], 11, 0x4BDECFA9);
    P(C, D, A, B, X[7], 16, 0xF6BB4B60);
    P(B, C, D, A, X[10], 23, 0xBEBFBC70);
    P(A, B, C, D, X[13], 4, 0x289B7EC6);
    P(D, A, B, C, X[0], 11, 0xEAA127FA);
    P(C, D, A, B, X[3], 16, 0xD4EF3085);
    P(B, C, D, A, X[6], 23, 0x04881D05);
    P(A, B, C, D, X[9], 4, 0xD9D4D039);
    P(D, A, B, C, X[12], 11, 0xE6DB99E5);
    P(C, D, A, B, X[15], 16, 0x1FA27CF8);
    P(B, C, D, A, X[2], 23, 0xC4AC5665);
#undef F
#define F(x, y, z) (y ^ (x | ~z))
    P(A, B, C, D, X[0], 6, 0xF4292244);
    P(D, A, B, C, X[7], 10, 0x432AFF97);
    P(C, D, A, B, X[14], 15, 0xAB9423A7);
    P(B, C, D, A, X[5], 21, 0xFC93A039);
    P(A, B, C, D, X[12], 6, 0x655B59C3);
    P(D, A, B, C, X[3], 10, 0x8F0CCC92);
    P(C, D, A, B, X[10], 15, 0xFFEFF47D);
    P(B, C, D, A, X[1], 21, 0x85845DD1);
    P(A, B, C, D, X[8], 6, 0x6FA87E4F);
    P(D, A, B, C, X[15], 10, 0xFE2CE6E0);
    P(C, D, A, B, X[6], 15, 0xA3014314);
    P(B, C, D, A, X[13], 21, 0x4E0811A1);
    P(A, B, C, D, X[4], 6, 0xF7537E82);
    P(D, A, B, C, X[11], 10, 0xBD3AF235);
    P(C, D, A, B, X[2], 15, 0x2AD7D2BB);
    P(B, C, D, A, X[9], 21, 0xEB86D391);
#undef F

    ctx->state[0] += A;
    ctx->state[1] += B;
    ctx->state[2] += C;
    ctx->state[3] += D;
}
