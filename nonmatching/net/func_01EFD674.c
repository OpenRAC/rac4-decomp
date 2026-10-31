/* Not matching yet: BYTES 15/124 (tools/try_func.py func_01EFD674 --diff). Not part of the build. */
extern void func_0011A518(void *, s32, s32);
extern s32 func_01EEDCD0(s32, s32, s32);
extern s32 D_0019D808;

// Sets up the object at arg0: copies 0x40 bytes from D_0019D808, clears two 0x64-byte buffers, then sets its fields.
void func_01EFD674(u8 *arg0) {
    func_01EEDCD0(arg0 + 0x38, &D_0019D808, 0x40);
    func_0011A518(arg0 + 0xBC, 0, 0x64);
    func_0011A518(arg0 + 0x120, 0, 0x64);
    *(s32 *)(arg0 + 0xB4) = 0xE;
    *(s32 *)(arg0 + 0x184) = -1;
    *(s32 *)(arg0 + 0x188) = -0x100;
    *(s32 *)(arg0 + 0xB8) = 0;
    *(s32 *)(arg0 + 0x18C) = 0;
    *(s32 *)(arg0 + 0x190) = 0;
    *(s32 *)(arg0 + 0x194) = 0;
}
