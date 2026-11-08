/* Not matching yet: SIZE ours 36 / retail 56 (tools/try_func.py func_00501988 --diff). Not part of the build. */
f32 D_00220AD4 = 0;
f32 D_00220AD8 = 0;
f32 D_00220AEC = 0;
f32 D_00220AF0 = 0;
f32 D_00220AF4 = 0;
f32 D_00220AF8 = 0;

/* Divide two pairs of globals and store the quotients in two more. */
void func_00501988(void) {
    D_00220AF4 = D_00220AD4 / D_00220AEC;
    D_00220AF8 = D_00220AD8 / D_00220AF0;
}
