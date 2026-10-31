/* Not matching yet: BYTES 14/128 (tools/try_func.py func_00472798 --diff). Not part of the build. */
/* Combines two func_00472690 results with func_004725D8 of the float arguments, passes them to func_004FE850 with D_222010, and stores the 128-bit result through the pointer argument. */
typedef int u128 __attribute__((mode(TI)));
extern f32 func_004725D8(f32 a0, f32 a1);
extern f32 func_00472690();
extern u128 func_004FE850(void *, f32, f32, f32);
extern u8 D_222010[];

void func_00472798(u128 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f0;

    temp_f23 = func_00472690();
    temp_f22 = func_00472690();
    temp_f0 = func_004725D8(fparg0, fparg1);
    *arg0 = func_004FE850(D_222010, temp_f0, temp_f23, temp_f22);
}
