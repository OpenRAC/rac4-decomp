/* Not matching yet: BYTES 7/64 (tools/try_func.py func_01EB6748 --diff). Not part of the build. */
/* Stores arg1 at offset 0 of arg0 when arg1 is 9 or more and arg0 is non-null with nonzero words at offsets 0 and 8; returns 0 when stored, else 2. */
s32 func_01EB6748(s32 *arg0, u32 arg1) {
    s32 var_v0;

    if ((arg0 == NULL) || (arg0[2] == 0) || (arg0[0] == 0)) {
        return 2;
    }
    var_v0 = 2;
    if (arg1 >= 9U) {
        arg0[0] = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
