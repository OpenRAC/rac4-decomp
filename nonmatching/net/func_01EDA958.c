/* Not matching yet: BYTES 27/52 (tools/try_func.py func_01EDA958 --diff). Not part of the build. */
/* Turn a run of bit numbers into a mask. */
u32 func_01EDA958(s32 arg0, u16 *arg1, u16 arg2) {
    u32 bit = 1;
    u32 mask = 0;

    while (arg2 != 0) {
        mask |= bit << *arg1++;
        arg2--;
    }
    return mask;
}
