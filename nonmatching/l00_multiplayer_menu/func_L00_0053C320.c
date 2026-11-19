/* Not matching yet: BYTES 16/84 (tools/try_func.py func_L00_0053C320 --diff). Not part of the build. */
extern s32 func_0012B5C8(s32 fd);

s32 func_L00_0053C320(u8 *arg0) {
    s32 value = 0;

    if (arg0 != 0) {
        if (*(s32 *)(arg0 + 0x10) != 0) {
            if (*(s32 *)(arg0 + 0xC) != 0) {
                func_0012B5C8(*(s32 *)(arg0 + 0x1C));
            }
            *(s32 *)(arg0 + 0xC) = 0;
            *(s32 *)(arg0 + 0x14) = 0;
        }
        value = 1;
    }
    return value;
}
