/* Not matching yet: BYTES 7/68 (tools/try_func.py func_001480B0 --diff). Not part of the build. */
/* cflags: -fno-opt-stack */
extern s32 func_0011D5D8(s32);
extern s32 D_001A0010[];
extern s32 D_001A0020[];

// Calls a helper on the first global, and on the second when the argument is set; returns 0.
s32 func_001480B0(s32 arg0) {
    func_0011D5D8((s32)D_001A0010);
    if (arg0 != 0) {
        func_0011D5D8((s32)D_001A0020);
    }
    return 0;
}
