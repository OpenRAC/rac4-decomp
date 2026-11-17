/* Not matching yet: BYTES 10/36 (tools/try_func.py func_L05_004C2008 --diff) (tools/try_func.py func_L05_004C2008 --diff). Not part of the build. */
s32 func_L05_004C2008(u8 *arg0) {
    u8 *v1;
    s32 r;

    v1 = *(u8 **)(arg0 + 0xAC);
    if (*(u8 *)(v1 + 0x2C) != 0) {
        r = *(u8 *)(v1 + 0x2D) == 0;
    } else {
        r = 0;
    }
    return r;
}
