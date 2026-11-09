/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 key[0x18];
    u8 *key2;
    s32 counter;
    s32 hash;
    s32 ctx;
} Type1;

s32 func_0051A6E0(s32);
void func_L00_00519490(s32, s32);
void func_L00_00519578(s32, void *, s32);
void func_L00_005195A8(s32, u8 *, s32 *);
s32 func_L00_0051A740(void);
void func_L00_0051A7B8(s32);
s32 func_L00_00525E80(void *arg0, void *arg1, s32 arg2);

/* Fills arg1 with arg2 bytes of keystream generated from the state, re-keying after each block. */
s32 func_L00_00525BE8(void *arg0, u8 *arg1, s32 arg2) {
    u8 buf[0x20];
    s32 len;
    Type1 *s;
    s32 ctx;
    s32 size;
    s32 n;
    s32 i;
    s32 a;
    s32 b;
    s32 more;

    s = *(Type1 **)((u8 *)arg0 + 0xC);
    ctx = s->ctx;
    if (ctx == 0) {
        ctx = func_L00_0051A740();
        if (ctx == 0) {
            return 0;
        }
    }
    func_L00_00525E80(arg0, arg1, arg2);
    n = 0;
    more = n < arg2;
    size = func_0051A6E0(s->hash);
    while (more) {
        func_L00_00519490(ctx, s->hash);
        func_L00_00519578(ctx, s, 0x18);
        func_L00_00519578(ctx, s->key2, 0x18);
        func_L00_00519578(ctx, &s->counter, 4);
        s->counter++;
        func_L00_005195A8(ctx, buf, &len);
        for (i = size; more && i != 0;) {
            i--;
            arg1[n] = buf[i];
            n++;
            more = n < arg2;
        }
        func_L00_00519490(ctx, s->hash);
        func_L00_00519578(ctx, s, 0x18);
        func_L00_00519578(ctx, s->key2, 0x18);
        func_L00_00519578(ctx, &s->counter, 4);
        func_L00_00519578(ctx, buf, size);
        func_L00_005195A8(ctx, buf, &len);
        a = (u32)(s->counter * (size / 2)) % 24;
        b = (a + size / 2) % 24;
        for (i = 0; i < size / 2; i++) {
            s->key[(a + i) % 24] ^= buf[i];
            s->key2[(b + i) % 24] ^= buf[i + size / 2];
        }
    }
    if (s->ctx == 0) {
        func_L00_0051A7B8(ctx);
    }
    return arg2;
}
