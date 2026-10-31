/* Not matching yet: BYTES 10/76 (tools/try_func.py func_01EA90F0 --diff). Not part of the build. */
extern s32 **D_0016819C_[];
#define D_0016819C (D_0016819C_[0])

/* Returns the first node of the list at D_0016819C whose word at 0x10 is arg0, or the node where the walk stops. */
s32 func_01EA90F0(s32 arg0) {
    s32 temp_v1;
    s32 *temp_a1;
    s32 *var_v1;

    var_v1 = *D_0016819C;
    if (var_v1 != NULL && var_v1[4] != arg0) {
        temp_a1 = var_v1;
        var_v1 = (s32 *) var_v1[1];
        while (1) {
            temp_v1 = (s32) var_v1 ^ (s32) temp_a1;
            if (temp_v1 == 0) {
                var_v1 = NULL;
            }
            if (var_v1 == NULL) {
                break;
            }
            if (var_v1[4] == arg0) {
                break;
            }
            var_v1 = (s32 *) var_v1[1];
        }
    }
    return (s32) var_v1;
}
