/* Not matching yet: BYTES 1/104 (tools/try_func.py func_01F0C720 --diff). Not part of the build. */
extern s32 func_01EEE12C(void);
extern void func_01EE6AF8(void *, s32);

// Passes the first non-empty child of the object returned by func_01EEE12C (offsets 0xA8, then 0xA4) to func_01EE6AF8.
void func_01F0C720(void *arg0, void *arg1, s32 arg2) {
    u8 *temp_v0;
    u8 *var_a0;
    s32 v;

    temp_v0 = (u8 *)func_01EEE12C();
    v = arg2;
    var_a0 = *(u8 **)(temp_v0 + 0xA8);
    if (var_a0 == NULL || *(s32 *)(var_a0 + 0x3A30) == 0) {
        var_a0 = *(u8 **)(temp_v0 + 0xA4);
        arg2 = 0;
        if (var_a0 == NULL || *(s32 *)(var_a0 + 0x3A30) == 0) {
            var_a0 = NULL;
        }
    }
    if (var_a0 != NULL) {
        func_01EE6AF8(var_a0, v);
    }
}
