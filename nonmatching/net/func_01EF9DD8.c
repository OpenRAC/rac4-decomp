/* Not matching yet: BYTES 7/64 (tools/try_func.py func_01EF9DD8 --diff). Not part of the build. */
// Store arg1 into the word at +8 of each of the (count + 1) 0xC-byte records at arg0+0x118.
void func_01EF9DD8(void *arg0, s32 arg1) {
    u8 *base;
    s32 var_a2;
    s32 var_v1;

    var_a2 = 0;
    if ((*(s32 *)((u8 *)arg0 + 0xBC) + 1) > 0) {
        base = *(u8 **)((u8 *)arg0 + 0x118);
        var_v1 = 0;
        do {
            *(s32 *)(base + var_v1 + 8) = arg1;
            var_a2 += 1;
            var_v1 += 0xC;
        } while (var_a2 < (*(s32 *)((u8 *)arg0 + 0xBC) + 1));
    }
}
