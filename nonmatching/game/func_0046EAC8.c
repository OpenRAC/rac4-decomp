/* Not matching yet: BYTES 15/260 (tools/try_func.py func_0046EAC8 --diff). Not part of the build. */
void func_004697C0(void *p, s32 n, s32 flags);
void func_00469800(void);
void func_0046DEF8(f32 a, f32 b);

void func_0046EAC8(u8 *arg0, f32 t, f32 u)
{
    s32 i;
    f32 frac;
    s32 next;
    u8 *base;
    s32 count;
    s32 off;
    u8 *a;
    u8 *b;

    i = (s32)t;
    frac = t - (f32)i;
    next = i + 1;
    base = *(u8 **)(arg0 + 0x1C);
    count = base[2];
    off = base[1];
    if (next == arg0[0x10]) {
        next = 0;
    }
    a = base + (off + i * count) * 16;
    b = base + (next * count + off) * 16;
    if (off != 0) {
        func_004697C0(base, off, 0x2000);
        func_00469800();
    }
    if (count != 0) {
        func_004697C0(a, count, 0x3000);
        func_00469800();
        func_004697C0(b, count, 0x3800);
        func_00469800();
    }
    func_0046DEF8(frac, u * u * (3.0f - (u + u)));
}
