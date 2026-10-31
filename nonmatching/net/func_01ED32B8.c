/* Not matching yet: BYTES 3/84 (tools/try_func.py func_01ED32B8 --diff). Not part of the build. */
// Runs the optional callback at +0x20 on the value at +0x38, then clears +0x34 and +0x30; returns -1 if arg0 or +0x38 is null.
s32 func_01ED32B8(void *arg0) {
    s32 ret;
    s32 temp_a0;
    void (*fp)(s32);

    if (arg0 == NULL || *(s32 *)((u8 *)arg0 + 0x38) == 0) {
        ret = -1;
    } else {
        temp_a0 = *(s32 *)((u8 *)arg0 + 0x38);
        fp = *(void (**)(s32))((u8 *)arg0 + 0x20);
        if (fp != 0) {
            fp(temp_a0);
        }
        *(s32 *)((u8 *)arg0 + 0x34) = 0;
        ret = 0;
        *(s32 *)((u8 *)arg0 + 0x30) = 0;
    }
    return ret;
}
