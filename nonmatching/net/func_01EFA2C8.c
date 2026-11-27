/* Not matching yet: BYTES 17/160 (tools/try_func.py func_01EFA2C8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
extern s32 func_0011AB04(u8 *);
extern void func_01EF9D10();
extern void func_01EEDDB0(s32, s32, s32, s32);
extern void func_01EFA604(void *, s32, s32);
extern void func_01EFAA2C(void *, s32);

void func_01EFA2C8(u8 *arg0, u8 *arg1) {
    s32 x;
    s32 n;
    s32 z;
    s32 y;
    u8 *p;

    p = arg0 + 0xCC;
    func_01EF9D10();
    x = func_0011AB04(arg1);
    n = *(s32 *)(arg0 + 0xB8);
    z = x + (x < (n - 1));
    y = (((x < n) ^ 0) == 0) ? n : z;
    func_01EEDDB0(*(s32 *)(arg0 + 0xB4), (s32)arg1, y + 1, n);
    func_01EFA604(arg0, *(s32 *)(arg0 + 0xB4), (s32)p);
    *(s32 *)(arg0 + 0xD4) = *(s32 *)p;
    *(s32 *)(arg0 + 0xF4) = *(s32 *)(arg0 + 0xF8);
    func_01EFAA2C(arg0, **(s32 **)(arg0 + 0x80));
}
