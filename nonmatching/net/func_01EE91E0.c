/* Not matching yet: BYTES 45/144 (tools/try_func.py func_01EE91E0 --diff) (tools/try_func.py func_01EE91E0 --diff). Not part of the build. */

s32 func_01EE91E0(u8 *arg0) {
    void **p = (void **)(*(u32 *)(arg0 + 0x6358) + 8);
    s32 i;
    void *e;
    void *vt;

    if (*p == 0)
        return 0;
    i = 0;
    do {
        e = *p;
        vt = *(void **)((u8 *)e + 0xB0);
        if (((s32 (*)(void *))*(void **)((u8 *)vt + 0x20))(e) != 0) {
            e = *p;
            vt = *(void **)((u8 *)e + 0xB0);
            return ((s32 (*)(void *))*(void **)((u8 *)vt + 0x3C))(e);
        }
        i++;
        p++;
    } while (i < 0x100 && *p != 0);
    return 0;
}
