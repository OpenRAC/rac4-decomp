/* Not matching yet: BYTES 15/100 (tools/try_func.py func_004CAEC8 --diff). Not part of the build. */
extern void func_0049C158(s32 param_a, s32 param_b, s32 source, s32 mode);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505B20(void);
extern u8 D_003D2618[];
extern u8 D_2218F8[];
// Calls func_0049C158 with the result of func_004A1A60 over D_2218F8 and word 0x14 of the 0x20-byte row at arg0.
void func_004CAEC8(s32 arg0) {
    s32 temp_s1;
    s32 row;

    temp_s1 = func_00505B20();
    row = *(s32 *)(D_003D2618 + (arg0 << 5) + 0x14);
    func_0049C158(temp_s1, 0, func_004A1A60((s32 *)D_2218F8, row), 0);
}
