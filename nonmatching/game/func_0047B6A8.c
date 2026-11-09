/* Not matching yet: BYTES 24/316 (tools/try_func.py func_0047B6A8 --diff). Not part of the build. */
/* cflags: -fno-opt-stack */
typedef unsigned int u128 __attribute__((mode(TI)));
extern void *func_00476690(void *object);
extern void func_0047B320(void *a0, s32 a1, u128 a2, f32 f12, f32 f13, f32 f14, f32 f15,
                          u8 a3, f32 f16, f32 f17, s32 t0, s32 t1, s32 t2, s32 t3,
                          f32 f18, f32 f19, s32 s0, s32 s1, s32 s2, s32 s3);

void func_0047B6A8(void *a0, s32 a1, u128 a2, s32 a3, s32 t0, u8 t1, s32 t2, s32 t3,
                   f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17, f32 f18, s32 s0)
{
    u8 *p = func_00476690(a0);
    if (p != NULL && p[0x3C] == 2) {
        return;
    }
    func_0047B320(a0, a1, a2, f13, f14, f15, f16, t1, f17, f18, t2, t3, a3, t0, f12, 1.0f, 0, 0, s0, 0);
}
