/* Not matching yet: BYTES 2/60 (tools/try_func.py func_004E5550 --diff). Not part of the build. */
void func_0045CA60(s32, s32, s32);
extern s32 D_00171B2C[];
extern s16 D_1DFC48[];

s32 D_003D2F78 = 0;

// Initialize globals and call func_0045CA60
void func_004E5550(void) {
    D_00171B2C[0] = 1;
    D_1DFC48[0] = 1;
    D_003D2F78 = 1;
    func_0045CA60(1, 1, -1);
}
