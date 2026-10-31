/* Not matching yet: BYTES 8/72 (tools/try_func.py func_01EC52E0 --diff). Not part of the build. */
extern void func_01EA8FD8(s32 a, void *b);
extern void func_01EC5618(s32 a, s32 b, s32 c, void *d, s32 e, s32 f);

/* Calls func_01EC5618 with fixed flags and a local buffer; arg0 is passed through. */
void func_01EC52E0(s32 arg0) {
    s32 buf[16];

    func_01EA8FD8(0, buf);
    func_01EC5618(arg0, 0x12, 0xFFFF, buf, 0x40, 0xC0);
}
