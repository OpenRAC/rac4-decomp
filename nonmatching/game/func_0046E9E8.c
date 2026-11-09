/* Not matching yet: BYTES 17/224 (tools/try_func.py func_0046E9E8 --diff). Not part of the build. */
extern void func_004697C0(void *a0, s32 a1, s32 a2);
extern void func_00469800();
extern void func_0046DC80(f32);

// Splits a frame time into whole/fraction, submits the header and the two neighbouring frame blocks, then calls func_0046DC80 with the fraction.
void func_0046E9E8(u8 *arg0, f32 t) {
    s32 i = (s32)t;
    s32 next = i + 1;
    u8 *data;
    s32 stride;
    s32 hdr;
    u8 *cur;
    u8 *nxt;
    f32 frac;

    frac = t - (f32)i;
    data = *(u8 **)(arg0 + 0x1C);
    if (next == arg0[0x10]) next = 0;
    stride = data[2];
    hdr = data[1];
    cur = data + (hdr + i * stride) * 16;
    nxt = data + (next * stride + hdr) * 16;
    if (hdr != 0) {
        func_004697C0(data, hdr, 0x2000);
        func_00469800();
    }
    if (stride != 0) {
        func_004697C0(cur, stride, 0x3000);
        func_00469800();
        func_004697C0(nxt, stride, 0x3800);
        func_00469800();
    }
    func_0046DC80(frac);
}
