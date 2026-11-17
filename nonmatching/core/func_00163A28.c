/* Not matching yet: BYTES 3/152 (tools/try_func.py func_00163A28 --diff). Not part of the build. */
extern void func_001582A8(s32, s32, void *, u64);
extern void func_00158598(s32);
extern void func_001596D8(void);
extern void func_00163960(void);
extern u8 D_1C2040[];
extern u32 D_1D2200[];

s32 func_00163A28(u8 *arg0) {
    u32 base;
    s32 i;

    func_00158598(D_1D2200[0x27]);
    func_001596D8();
    *(s32 *)(arg0 + 4) = (s32)&D_1D2200[0x27];
    D_1D2200[0x27] = 0xFFFFFFFF;
    base = (u32)D_1C2040;
    base += 0x8000;
    i = *(s32 *)arg0;
    func_001582A8(*(s32 *)((u8 *)(base + (i << 3) + 0x5410)) +
                  *(s32 *)((u8 *)(base + 0x4BB4)), 0, func_00163960, (u32)arg0);
    return 1;
}
