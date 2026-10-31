/* Not matching yet: BYTES 1/64 (tools/try_func.py func_0047D448 --diff). Not part of the build. */
extern u8 D_00171B80[];

/* Updates some flags and values in an array based on conditions. */
void func_0047D448(s32 arg0, s32 arg1) {
    u8 *ptr;

    if ((u32)arg0 < 8) {
        ptr = D_00171B80 + arg0;
        ptr[0x1C] = 1;
        if (arg1 & 1) {
            D_00171B80[0x26] = arg0;
        }
        if (arg1 & 2) {
            D_00171B80[0x27] = arg0;
        }
    }
}
