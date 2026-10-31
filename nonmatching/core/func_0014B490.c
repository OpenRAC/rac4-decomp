/* Not matching yet: BYTES 5/108 (tools/try_func.py func_0014B490 --diff). Not part of the build. */
/* cflags: -fno-opt-stack */
extern void func_0014A1D8(s32 a, s32 b);
extern void func_0014A5E8(s32 a, s32 b, s32 c, s32 d);
extern s32 func_0014D0E0();

// Stores the result of func_0014D0E0 through arg2, then runs func_0014A5E8 and func_0014A1D8 on it.
void func_0014B490(s32 arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 temp_v0;

    temp_v0 = func_0014D0E0();
    *arg2 = temp_v0;
    func_0014A5E8(arg0, arg3, temp_v0, arg1);
    func_0014A1D8(arg1, *arg2);
}
