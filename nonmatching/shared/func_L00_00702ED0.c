/* Not matching yet: BYTES 59/144 (tools/try_func.py func_L00_00702ED0 --diff). Not part of the build. */
extern void *func_006A9190(u8);
extern void func_L00_005BCBF0(void *, void *, s32);
extern s32 D_00172378[];

s32 func_L00_00702ED0(u8 *arg3) {
    s32 a = 0;
    void *p = func_006A9190(*arg3);
    if (p != NULL) {
        void *q;
        if (*(s32 *)((char *)p + 0x25CC) == 0x9B) {
            goto check;
        }
        q = *(void **)((char *)p + 0x2F28);
        if (q == NULL) {
            goto check;
        }
        a = *(s32 *)((char *)q + 4) != 0;
    }
check:
    if ((a & 0xFF) != 0) {
        func_L00_005BCBF0((char *)p + 0x2F2C, arg3, 0x1C);
        *(s32 *)((char *)p + 0x2F48) = D_00172378[0];
    }
    return 0x1C;
}
