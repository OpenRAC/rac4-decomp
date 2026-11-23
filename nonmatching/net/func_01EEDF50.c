/* Not matching yet: BYTES 9/144 (tools/try_func.py func_01EEDF50 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-loops=1 */
extern s32 func_0011AB04(u8 *);
extern s32 func_0011AE00(char *, char *, s32);

s32 func_01EEDF50(char *arg0, char *arg1) {
    s32 i = 0;
    s32 n = func_0011AB04((u8 *)arg0);
    s32 m = func_0011AB04((u8 *)arg1);

    if (n > 0) {
        for (i = 0; i < n; i++) {
            if (func_0011AE00(arg0 + i, arg1, m) == 0) return i;
        }
    }
    return -1;
}
