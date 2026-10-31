/* Not matching yet: BYTES 16/120 (tools/try_func.py func_01EFDE94 --diff). Not part of the build. */
extern void func_0011A518(void *, s32, s32);
extern s32 func_01EEDCD0(s32, s32, s32);
extern s32 D_0019D8E8[];

/* Fills two 0x64-byte areas at offsets 0xBC and 0x120 and sets the state words at 0xB4, 0x184, 0x188, 0x190, 0xB8 and 0x18C. */
void func_01EFDE94(u8 *arg0) {
    func_01EEDCD0((s32)(arg0 + 0x38), (s32)D_0019D8E8, 0x40);
    func_0011A518(arg0 + 0xBC, 0, 0x64);
    func_0011A518(arg0 + 0x120, 0, 0x64);
    *(s32 *)(arg0 + 0xB4) = 0xE;
    *(s32 *)(arg0 + 0x184) = -1;
    *(s32 *)(arg0 + 0x188) = -0x100;
    *(s32 *)(arg0 + 0xB8) = 0;
    *(s32 *)(arg0 + 0x18C) = 0;
    *(s32 *)(arg0 + 0x190) = 0;
}
