/* Not matching yet: BYTES 4/124 (tools/try_func.py func_004B8888 --diff). Not part of the build. */
/* Flips the flag byte at +0xBC of D_00171D38 when arg0 is set, then passes a table entry chosen by that flag through func_0045E038 into func_00505238. */
extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00505238();
extern s32 D_003D93E0_[];
#define D_003D93E0 (D_003D93E0_[0])
extern u8 D_00171D38[];
extern u8 D_221790[];

s32 D_0021F880 = 0;

void func_004B8888(s32 arg0) {
    s32 g;
    s32 r;
    s32 v;

    if (arg0 != 0) {
        D_00171D38[0xBC] = (u8)(D_00171D38[0xBC] == 0);
        func_00497980(0x10);
    }
    g = D_003D93E0;
    r = func_004A1A60((s32 *)D_221790, g);
    v = func_0045E038(((s32 *)&D_0021F880)[D_00171D38[0xBC]]);
    func_00505238(r, v);
}
