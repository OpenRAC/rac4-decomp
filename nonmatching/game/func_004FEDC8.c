/* Not matching yet: BYTES 15/100 (tools/try_func.py func_004FEDC8 --diff). Not part of the build. */
extern s32 func_004FF910();
extern void *func_005010E0();
extern char D_222038[];

/* Look up the entry at D_222038 (or the one func_005010E0 returns), then pass its indexed value and arg0's field 0x10 to func_004FF910. */
void func_004FEDC8(char *arg0) {
    char *var_v0;
    s32 var_a0;
    char *temp_v1;

    if (*(char **)(D_222038 + 4) != NULL) {
        var_v0 = D_222038;
    } else {
        var_v0 = func_005010E0();
    }
    temp_v1 = *(char **)(var_v0 + 4);
    var_a0 = 0;
    if (temp_v1 != NULL) {
        var_a0 = *(s32 *)(temp_v1 + (*(s32 *)(temp_v1 + 0x14) << 2));
    }
    func_004FF910(var_a0, *(s32 *)(arg0 + 0x10));
}
