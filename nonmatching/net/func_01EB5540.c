/* Not matching yet: BYTES 38/124 (@ee32-030210, was 51/124). Not part of the build. */
/* cflags: @ee32-030210  */
extern s32 D_001694FC[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];

s32 func_01E9CFD0(s32 *a0, s32 *a1, s32 a2, s32 a3, s32 *a4, s32 a5);

s32 func_01EB5540(s32 arg0, s32 arg1, s32 *arg2)
{
    s32 local = 0;
    s32 var;
    s32 res;

    var = 5;
    if (D_001694FC[0] != 0) {
        var = 2;
        if (arg0 >= 0) {
            *arg2 = 0;
            res = func_01E9CFD0(D_1B26C0, D_1B2700, arg0, arg1, &local, 0);
            if (res < 0) {
                var = 0xC350;
            } else {
                *arg2 = res;
                var = 0;
            }
        }
    }
    return var;
}
