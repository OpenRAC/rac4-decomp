/* Not matching yet: BYTES 16/108 (tools/try_func.py func_00122020 --diff). Not part of the build. */
/* returns the length of the leading part of arg0 that holds no character from arg1 */
s32 func_00122020(s8 *arg0, s8 *arg1) {
    s8 *temp_t0;
    s8 *var_a0;
    s8 *var_a2;
    s8 temp_v1;
    s8 temp_v1_2;
    u8 var_a3;

    var_a0 = arg0;
    temp_t0 = var_a0;
    var_a3 = (u8) *var_a0;
    if (*var_a0 != 0) {
loop_1:
        var_a2 = arg1;
        temp_v1 = *var_a2;
        if (temp_v1 != 0) {
            if ((s8) var_a3 != temp_v1) {
loop_3:
                var_a2 += 1;
                temp_v1_2 = *var_a2;
                if (temp_v1_2 != 0) {
                    if (*var_a0 == temp_v1_2) {
                        goto block_5;
                    }
                    goto loop_3;
                }
                goto block_6;
            }
block_5:
            if (*var_a2 == 0) {
                goto block_6;
            }
        } else {
block_6:
            var_a0 += 1;
            var_a3 = (u8) *var_a0;
            if (*var_a0 != 0) {
                goto loop_1;
            }
        }
    }
    return var_a0 - temp_t0;
}
