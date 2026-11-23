/* Not matching yet: BYTES 25/140 (tools/try_func.py func_01EFB300 --diff). Not part of the build. */
extern void func_01EFB38C(void *);
extern void func_01EFA604(void *, s32, void *);
extern void func_01EFAA2C(void *, s32);
extern s32 func_01EFB44C(void *, s32, s32);

void func_01EFB300(u8 *arg0)
{
    s32 t;
    s32 h;

    func_01EFB38C(arg0);
    func_01EFA604(arg0, *(s32 *)(arg0 + 0xB4), arg0 + 0xCC);
    t = func_01EFB44C(arg0, *(s32 *)(arg0 + 0xB4), *(s32 *)(arg0 + 0xD4));
    h = *(s32 *)(arg0 + 0xF0);
    *(s32 *)(arg0 + 0xF4) = t;
    if (t < h) {
        while (t < h - 1)
            h--;
        *(s32 *)(arg0 + 0xF0) = h;
    }
    func_01EFAA2C(arg0, *(s32 *)(*(s32 *)(arg0 + 0x80)));
}
