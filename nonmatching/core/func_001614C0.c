/* Not matching yet: BYTES 14/104 (tools/try_func.py func_001614C0 --diff). Not part of the build. */
s32 D_0021E020 = 0;
s32 D_0021E024 = 0;
s32 func_001528A0(s32);

/* Clears *arg0; when the queued value is not -1 and the pending flag is clear, sends the value and sets the flag. */
s32 func_001614C0(s32 *arg0) {
    *arg0 = 0;
    if (D_0021E020 == -1) {
        return 1;
    }
    if (D_0021E024 == 1) {
        return 1;
    }
    if (func_001528A0(D_0021E020) == 0) {
        *arg0 = 1;
        D_0021E024 = 1;
        return 0;
    }
    return 1;
}
