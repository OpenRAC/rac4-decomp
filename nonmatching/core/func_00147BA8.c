/* Not matching yet: BYTES 10/132 (tools/try_func.py func_00147BA8 --diff). Not part of the build. */
extern void func_00147738(s32 arg0);
void func_00147B00(void *, s32, s32);
void func_00147B68(void);
extern void func_001481C0(s32, s32, s32);
extern s32 D_0016F750[];
extern s32 D_0016F810[];
extern s32 D_0016F820[];
extern u8 D_0019FA40[];
extern u8 D_0019FF50[];
extern s32 D_001A0000[];
extern s32 D_001A0004[];

/* Runs the setup sequence once when the state word at D_0016F750 is 4, then marks D_0016F810 as 1. */
s32 func_00147BA8(void) {
    if (D_0016F750[0] == 4) {
        func_00147738(D_0016F810[0]);
        func_00147B00(D_0019FA40, 0x70003210, D_001A0000[0]);
        func_001481C0(D_0016F820[0], (s32)D_0019FF50, D_001A0004[0]);
        func_00147B68();
        D_0016F810[0] = 1;
    }
    return 0;
}
