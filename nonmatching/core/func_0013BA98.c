/* Not matching yet: BYTES 16/120 (tools/try_func.py func_0013BA98 --diff). Not part of the build. */
extern void *func_0013B8C8(s32 arg0, s32 arg1, void *out);
extern u8 D_1AF010[];

// Returns 0x63 when the record word at +0x10 is clear, else reads the byte record func_0013B8C8 fills and maps (6, 2) to 5.
u8 func_0013BA98(s32 arg0, s32 arg1) {
    u8 out[0x80];
    u8 *rec;

    rec = D_1AF010 + (arg1 * 0x1C + arg0 * 0x70);
    if (*(s32 *)(rec + 0x10) == 0) {
        return 0x63;
    }
    func_0013B8C8(arg0, arg1, out);
    if (out[0x70] == 6) {
        if (out[0x71] == 2) {
            return 5;
        }
    }
    return out[0x70];
}
