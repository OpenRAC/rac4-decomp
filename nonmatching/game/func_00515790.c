/* Not matching yet: BYTES 8/80 (tools/try_func.py func_00515790 --diff). Not part of the build. */
// Clamps the index to 0x1F and to the count at 0x2C74, then returns the float in the ring slot at 0x28F0.
f32 func_00515790(u8 *a0, s32 a1) {
    s32 a2;
    s32 a3;
    s32 v0;
    s32 v1;
    s32 m1;

    m1 = -1;
    a2 = (a1 < 0x20) ? a1 : 0x1F;
    a3 = *(s32 *)(a0 + 0x2C74);
    a2 = (a3 < a2) ? a3 : a2;
    v0 = *(s32 *)(a0 + 0x2C70) - a2;
    v1 = v0 + 0x1F;
    v0 = (m1 < v1) ? v1 : v0 + 0x3E;
    v1 = v1 - ((v0 >> 5) << 5);
    return *(f32 *)(a0 + (v1 << 2) + 0x28F0);
}
