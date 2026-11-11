/* Not matching yet: SIZE ours 56 / retail 40 (tools/try_func.py func_L00_00774BB0 --diff). Not part of the build. */
/* Round the value up to a multiple of four and report the distance plus 0x130. */
s32 func_L00_00774BB0(s32 arg0) {
    s32 value = arg0;
    s32 remainder = arg0 % 4;

    if (remainder != 0) {
        value += 4 - remainder;
    }
    return value - arg0 + 0x130;
}
