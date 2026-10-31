/* Not matching yet: BYTES 8/88 (tools/try_func.py func_01EA95C0 --diff). Not part of the build. */
extern void func_0011EFB0(s32 arg0);
extern s32 D_001681AC_[];
#define D_001681AC (D_001681AC_[0])

/* Call the handler at D_001681AC with *arg0 (or func_0011EFB0 when it is null), then clear *arg0 if it was nonzero; returns 0. */
s32 func_01EA95C0(s32 *arg0) {
    s32 temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        if (D_001681AC == 0) {
            func_0011EFB0(temp_a0);
        } else {
            ((void (*)(s32))D_001681AC)(temp_a0);
        }
        *arg0 = 0;
    }
    return 0;
}
