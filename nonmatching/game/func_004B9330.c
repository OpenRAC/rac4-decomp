/* Not matching yet: BYTES 6/124 (tools/try_func.py func_004B9330 --diff). Not part of the build. */
/* Looks up the slot for the current index, frees its pointer if set and clears it, and calls func_0049B0D8 on the index. */
extern void func_00499CE0(s32 arg0);
extern void func_0049B0D8(s32 arg0);
extern void func_0049D398(s32, s32, s32);
extern void func_004B99A8(void);
extern s32 func_00505B20(void);
extern s32 D_2217B0;
extern u8 D_2217B8[];

void func_004B9330(void) {
    s32 idx;
    s32 ptr;
    u8 *slot;

    idx = func_00505B20();
    slot = D_2217B8 + (idx << 4);
    func_0049D398(idx, 0, D_2217B0);
    func_004B99A8();
    ptr = *(s32 *)(slot + 0xC);
    if (ptr != 0) {
        func_00499CE0(ptr);
        *(s32 *)(slot + 0xC) = 0;
    }
    func_0049B0D8(idx);
}
