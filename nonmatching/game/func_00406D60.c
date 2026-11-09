/* Not matching yet: BYTES 57/536 (tools/try_func.py func_00406D60 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
typedef struct {
    u8 pad0[0x10];
    u8 sub[0x38];
    s32 unk48;
    u8 pad4C[0xC];
    s32 unk58;
    u8 pad5C[8];
    s32 unk64;
    s32 unk68;
    u32 unk6C;
    s32 unk70;
    u32 unk74;
} Type1;

extern void func_00403330(s32 dst, s32 src, u32 n);
extern s32 func_004074A8(void *a0, s32 a1, s32 a2, s32 a3, u32 *a4, s32 a5, u32 a6, s32 a7);

s32 func_00406D60(Type1 *s, s32 a1, u32 *out, u32 avail, s32 src, u32 len, s32 a6, s32 a7) {
    u32 done;
    u32 pos;
    u32 mode;
    u32 total;
    u32 bs;
    u32 lim;

    *out = 0;
    pos = s->unk6C;
    mode = s->unk64;
    done = 0;
    total = pos + len;
    bs = s->unk74;
    if (mode == 2) {
        if (avail < len) return 0x218;
        return func_004074A8(s->sub, s->unk48, s->unk58, a1, out, src, len, a7);
    }
    lim = bs - (mode == 0);
    if (lim >= total) {
        func_00403330(s->unk70 + pos, src, len);
        s->unk6C += len;
        return 0;
    }
    {
        u32 n;
        s32 dst;
        s32 p;
        u32 got;
        s32 ret;
        n = total - (mode > 0);
        n = (n / bs) * bs;
        if (avail < n) return 0x218;
        dst = a1;
        done = 0;
        p = src;
        if (pos != 0) {
            p = s->unk70;
            func_00403330(p + pos, src, bs - pos);
            ret = func_004074A8(s->sub, s->unk48, s->unk58, dst, &done, p, bs, a7);
            if (ret != 0) return ret;
            got = done;
            p = src + bs - pos;
            dst += got;
            *out = got;
        } else {
            got = 0;
        }
        if (got < n) {
            ret = func_004074A8(s->sub, s->unk48, s->unk58, dst, &done, p, n - got, a7);
            if (ret != 0) return ret;
            *out += done;
        }
        if (n < total) {
            u32 r = total - n;
            func_00403330(s->unk70, src + len - r, r);
            s->unk6C = r;
        } else {
            s->unk6C = 0;
        }
        return 0;
    }
}
