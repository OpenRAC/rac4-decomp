/* Not matching yet: BYTES 2/92 (tools/try_func.py func_01EC9060 --diff). Not part of the build. */
extern s32 D_00167F38;
extern s32 D_1B6A50_[];
#define D_1B6A50 (D_1B6A50_[0])

s32 func_01EA4570(u32);
void func_01EC8FF0(s32);

/* calls the two helpers four times when the table at D_1B6A50 is set, then clears a word of the object at D_00167F38 */
void func_01EC9060(void) {
    u32 temp_a0;
    u32 var_s0;
    s32 temp_v;

    if (D_1B6A50 != 0) {
        var_s0 = 0;
        temp_a0 = var_s0;
        do {
            temp_v = func_01EA4570(temp_a0);
            var_s0 += 1;
            func_01EC8FF0(temp_v);
            temp_a0 = var_s0;
        } while (var_s0 < 4U);
    }
    if ((u8 *)D_00167F38 != NULL) {
        *(s32 *)((u8 *)D_00167F38 + 0x128) = 0;
    }
}
