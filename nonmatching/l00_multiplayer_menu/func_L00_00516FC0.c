/* Not matching yet: BYTES 40/196 (tools/try_func.py func_L00_00516FC0 --diff). Not part of the build. */
/* cflags: @ee29 */
extern void func_0011A518(void *, s32, s32);
extern void *func_004FAD00(void *, s32, s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);

s32 func_L00_00516FC0(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;

    var_s0 = arg1;
    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0));
    if (temp_v1 < var_s0) {
        temp_a2 = (*(s32 *)((u8 *)(arg0) + 8));
        temp_a0 = (*(s32 *)((u8 *)(arg0) + 4));
        if (temp_a2 >= var_s0) {
            s32 rem = var_s0 - temp_v1;
            func_0011A518((u8 *)(temp_a0) + temp_v1, 0, rem);
            (*(s32 *)((u8 *)(arg0) + 0)) = var_s0;
            return var_s0;
        }
        temp_s2 = var_s0 + 0x10;
        if (temp_a0 == 0) {
            var_v0 = (s32)func_L00_004FACD8(temp_s2);
        } else {
            var_v0 = (s32)func_004FAD00(temp_a0, temp_s2, temp_a2);
        }
        if (var_v0 == 0) {
            var_s0 = 0;
            func_L00_004F84C8(7, 0x64, 0x21, 0, 0);
            goto ret;
        }
        (*(s32 *)((u8 *)(arg0) + 8)) = temp_s2;
        (*(void **)((u8 *)(arg0) + 4)) = (void *)var_v0;
    }
    (*(s32 *)((u8 *)(arg0) + 0)) = var_s0;
ret:
    return var_s0;
}
