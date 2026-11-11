/* Not matching yet: SIZE ours 40 / retail 52 (tools/try_func.py func_01EBD718 --diff). Not part of the build. */
/* The address after the two-byte count when the flag bit is set. */
u8 *func_01EBD718(u8 *arg0) {
    u16 count;

    if ((*(u16 *)arg0) & 0x4000) {
        count = *(u16 *)(arg0 + 2);
        return arg0 + 4 + (count << 1);
    }
    return arg0 + 2;
}
