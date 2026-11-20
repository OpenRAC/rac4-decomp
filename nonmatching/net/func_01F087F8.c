/* Not matching yet: BYTES 22/144 (tools/try_func.py func_01F087F8 --diff). Not part of the build. */
/* cflags: -fno-strength-reduce */
extern void func_01EEA034(s32);
extern s32 func_01EEE13C(void);
extern s32 func_01EF0550(s32, s32);
extern void func_01F088BC(void *arg0, s32 arg1);

void func_01F087F8(s32 arg0, s32 arg1) {
    s32 var_s2;
    s32 var_s3;
    s32 *temp_s0;

    if (arg1 == 0) {
        var_s3 = 0x8B90;
        func_01EEA034(arg0 + 0xB8);
        var_s2 = 1;
        func_01F088BC(arg0, 0);
        do {
            temp_s0 = (s32 *)(var_s3 + (s32)(arg0 + 8));
            var_s3 += 0x18;
            if (*temp_s0 != 0) {
                func_01EF0550(func_01EEE13C(), *temp_s0);
                *temp_s0 = 0;
            }
            var_s2 -= 1;
        } while (var_s2 >= 0);
    }
}
