/* Not matching yet: BYTES 7/100 (tools/try_func.py func_L00_00517208 --diff) (tools/try_func.py func_L00_00517208 --diff). Not part of the build. */
/* cflags: @sn274 -O2 -G0 */
void *func_0052D728(void *arg0);

s32 func_L00_00517208(void *arg0, u8 *arg1) {
    u8 *t;
    s32 r = 0;

    t = func_0052D728(arg0);
    if (t != 0) {
        if (arg1 != 0) {
            *(u64 *)(arg1 + 8) = *(u32 *)t;
            *(s32 *)(arg1 + 0x10) = *(s32 *)(t + 8);
            *(s32 *)arg1 = *(s32 *)(t + 4);
            r = 1;
        }
    }
    return r;
}
