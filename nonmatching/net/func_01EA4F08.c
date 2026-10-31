/* Not matching yet: BYTES 1/96 (tools/try_func.py func_01EA4F08 --diff). Not part of the build. */
// Clears the halfword at arg1 and sets flag bits from arg0 (0x10 -> 0x2000, 0x40 -> 0x4000, 0x80 -> 0x1000); returns 0, or 0x17 when arg1 is null.
s32 func_01EA4F08(s8 arg0, u16 *arg1) {
    s32 var_v0;
    s32 f80;
    s32 f10;
    s32 f40;

    var_v0 = 0x17;
    f10 = arg0 & 0x10;
    f40 = arg0 & 0x40;
    f80 = arg0 & 0x80;
    if (arg1 != NULL) {
        *arg1 = 0;
        if (f10) {
            *arg1 = 0x2000;
        }
        if (f40) {
            *arg1 |= 0x4000;
        }
        if (f80) {
            *arg1 |= 0x1000;
        }
        var_v0 = 0;
    }
    return var_v0;
}
