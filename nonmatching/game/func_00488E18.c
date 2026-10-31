/* Not matching yet: BYTES 12/104 (tools/try_func.py func_00488E18 --diff). Not part of the build. */
/* Calls func_001596D8, stores 0xFFFFFFFF at D_1D2200+0x9C, then calls func_001582A8 with a sum of two fields of D_1C2040 block at +0x8000. */
extern void func_001596D8(void);
extern void func_001582A8(s32, s32, void *, u64);
extern void func_00488DE8(void);
extern s32 D_1C2040[];
extern s32 D_1D2200[];

void func_00488E18(void) {
    s32 off;
    u8 *base;
    u8 *q;
    s32 t0;
    s32 a0;

    func_001596D8();
    off = 0x8000;
    base = (u8 *)D_1C2040;
    base = base + off;
    a0 = *(s32 *)(base + 0x4BD0);
    t0 = *(s32 *)(base + 0x4BB4);
    q = (u8 *)D_1D2200;
    *(u32 *)(q + 0x9C) = 0xFFFFFFFF;
    func_001582A8(t0 + a0, 0,
                  (void *)((u8 *)func_00488DE8 + 0x18),
                  (u64)(u32)(q + 0x9C));
}
