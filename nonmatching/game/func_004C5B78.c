/* Not matching yet: BYTES 14/108 (tools/try_func.py func_004C5B78 --diff). Not part of the build. */
extern s32 func_00505B20(void);
extern u8 D_30B9D8[];

/* Returns whether the block at D_30B9D8 entry arg0 (or the indexed entry when arg0 is negative) has its word at +0x8 not equal to 1 */
s32 func_004C5B78(s32 arg0) {
    s32 var_s0;
    u8 *temp_v1;
    u8 *var_v0;

    var_s0 = arg0;
    temp_v1 = (u8 *)((func_00505B20() * 0xB30) + D_30B9D8 + 0xAB4);
    var_v0 = NULL;
    if (var_s0 >= 0) {
        var_v0 = *(u8 **)(temp_v1 + 0x34) + (var_s0 * 0x18);
    } else {
        var_s0 = *(s32 *)(temp_v1 + 0x54);
        if (var_s0 >= 0) {
            var_v0 = *(u8 **)(temp_v1 + 0x34) + (var_s0 * 0x18);
        }
    }
    return *(s32 *)(*(u8 **)(var_v0 + 0x8) + 0x8) != 1;
}
