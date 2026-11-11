/* Not matching yet: SIZE ours 68 / retail 72 (tools/try_func.py func_004AB120 --diff). Not part of the build. */
extern u8 D_308B80[];

/* True when the record is live and in neither of the two idle states. */
s32 func_004AB120(s32 arg0) {
    u8 *entry = D_308B80 + arg0 * 0x170;
    s32 state;
    s32 result;

    result = 0;
    if ((*(s32 *)(entry + 0x158)) != -1) {
        state = *(s32 *)entry;
        if (state != 7) {
            result = (state ^ 8) != 0;
        }
    }
    return result;
}
