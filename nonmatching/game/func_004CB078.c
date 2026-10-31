/* Not matching yet: BYTES 6/116 (tools/try_func.py func_004CB078 --diff). Not part of the build. */
extern void func_004CA1D0(int arg0, int arg1);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern u8 D_0021EE18;
s32 D_0021FA2C = 0;

// Starts the action selected by arg0, or opens the pause menu when no mode is given, using flag D_0021EE18.
void func_004CB078(s32 arg0) {
    int var_a0;

    if (arg0 != 0) {
        if (D_0021EE18 != 0) {
            D_0021FA2C = 1;
            func_004E21D8(0xE, 0, 0);
            var_a0 = 2;
        } else {
            var_a0 = 0xF;
        }
        func_004CA1D0(var_a0, 0);
        return;
    }
    func_004E21D8(0xC, 0, 0);
    func_004CA1D0(1, 0);
}
