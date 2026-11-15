/* Not matching yet: BYTES 5/124 (tools/try_func.py func_01EBCE60 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
s32 func_01EC2298(s32, s32);

s32 func_01EBCE60(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 off;
    s32 r;
    u8 *p;

    i = arg1 & 0xFFFF;
    off = ((i << 2) + i) << 4;
    if (arg0 == 0) {
        return 2;
    }
    p = (u8 *)(off + *(s32 *)(arg0 + 0x184));
    r = *(s32 *)(p + 4);
    if (r != 0) {
        r = func_01EC2298(r, arg2);
        if (r != 0) {
            return r;
        }
    } else {
        r = *(s32 *)(p + 8);
        if (r != 0) {
            r = func_01EC2298(r, arg2);
            if (r != 0) {
                return r;
            }
        }
    }
    return 0;
}
