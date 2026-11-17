/* Not matching yet: BYTES 4/144 (tools/try_func.py func_01EE91E0 --diff) (tools/try_func.py func_01EE91E0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-loops=1 -fno-gcse -mno-split-addresses */
s32 func_01EE91E0(u8 *arg0) {
    s32 i = 0;
    void **p = (void **)((u8 *)*(u32 *)(arg0 + 0x6358) + 8);
    void **q;
    void *e;
    void *vt;

    if (*p != 0) {
        q = p;
        do {
            e = *q;
            vt = *(void **)((u8 *)e + 0xB0);
            if (((s32 (*)(void *))*(void **)((u8 *)vt + 0x20))(e) != 0) {
                e = *q;
                vt = *(void **)((u8 *)e + 0xB0);
                return ((s32 (*)(void *))*(void **)((u8 *)vt + 0x3C))(e);
            }
            i++;
            q++;
        } while (i < 0x100 && *q != 0);
    }
    return 0;
}
