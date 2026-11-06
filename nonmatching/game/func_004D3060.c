/* Not matching yet: BYTES 10/232 (tools/try_func.py func_004D3060 --diff). Not part of the build. */
extern s32 func_00157F98(void);
extern void func_00158868(s32 arg0);
extern void func_0047EF38(void);
extern void func_00489458(s32 arg0);
extern void func_0048A060(s32 arg0, s32 arg1);
extern void func_0048FA80(void *o);
extern s32 func_0049B120(s32 index);
extern void *func_004D36E0(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern void func_00501498(s32 *arg0);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern s32 func_00505C90(s32 arg0);
extern void *D_0021DDCC;
typedef struct {
    s32 f0;
    u8 pad4[0x4B];
    u8 f4F;
} Type1;
extern Type1 D_003D9BE0[];
extern s32 D_002214D0;
u8 D_0021FB2C = 0;

// Level/mode setup: reset several subsystems, store arg0 in D_003D9BE0 unless locked, and refresh.
void func_004D3060(s32 arg0) {
    s32 saved;

    func_0047EF38();
    func_00158868(0xCD);
    if (func_0049B120(0) != 0x18) {
        func_00489458(0);
    }
    func_0048A060((s32)&D_002214D0, 1);
    func_00157F98();
    if (D_003D9BE0[0].f4F == 0) {
        D_003D9BE0[0].f0 = arg0;
    }
    saved = func_00505B20();
    func_00505AD8(4);
    func_00501498(func_004D36E0());
    func_00505C90((s32)func_004D36E0());
    func_00505AD8(saved);
    if (D_0021FB2C != 0) {
        D_0021FB2C = 0;
        func_004E21D8(-1, 0, 0);
    }
    if (D_0021DDCC != 0) {
        func_0048FA80(D_0021DDCC);
    }
}
