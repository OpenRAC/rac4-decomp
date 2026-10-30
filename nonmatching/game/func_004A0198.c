/* Not matching yet: BYTES 6/60 (tools/try_func.py func_004A0198 --diff). Not part of the build. */
extern void func_00505238(s32, s32);
extern char D_307254[];

// Stores arg1 at offset 0x4C in the 512-byte entry arg0 of D_307254, then calls func_00505238.
void func_004A0198(s32 arg0, s32 arg1) {
    s32 *p;
    p = (s32 *)(D_307254 + (arg0 << 9));
    p[0x13] = arg1;
    func_00505238((arg0 << 6) + 0x14000C, arg1);
}
