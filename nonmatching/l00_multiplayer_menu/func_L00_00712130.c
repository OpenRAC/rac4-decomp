/* Not matching yet: BYTES 32/108 (tools/try_func.py func_L00_00712130 --diff). Not part of the build. */
extern void func_L00_007107F0(void *arg0, void *arg1);

void func_L00_00712130(s8 *arg0, s8 *arg1) {
    func_L00_007107F0(arg0, arg1);
    *(s32 *)(arg0 + 0x5C) = *(s32 *)(arg1 + 0x40);
    *(s32 *)(arg0 + 0x60) = *(s32 *)(arg1 + 0x44);
    *(s32 *)(arg0 + 0x7C) = 0x80808080;
    *(u8 *)(arg0 + 0x6C) = *(u8 *)(arg1 + 0x48);
    *(s32 *)(arg0 + 0x70) = *(s32 *)(arg0 + 0x64) = *(s32 *)(arg0 + 0x68) = -1;
    *(s32 *)(arg0 + 0x74) = 0;
    *(u8 *)(arg0 + 0x78) = 0;
}
