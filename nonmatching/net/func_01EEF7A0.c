/* Not matching yet: BYTES 4/68 (tools/try_func.py func_01EEF7A0 --diff). Not part of the build. */
extern void func_0011A518(void *, s32, s32);
/* Sets the word at 0x204 to -1, then clears 0x101 bytes at the object and again at offset 0x101. */
void func_01EEF7A0(u8 *a0) {
    *(s32 *)(a0 + 0x204) = -1;
    func_0011A518(a0, 0, 0x101);
    func_0011A518(a0 + 0x101, 0, 0x101);
}
