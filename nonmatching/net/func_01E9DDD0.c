/* Not matching yet: BYTES 13/104 (tools/try_func.py func_01E9DDD0 --diff). Not part of the build. */
/* Clears a handle's state and returns 0, or 0x17 when the handle is null. */
extern void func_0011A518(void *, s32, s32);
extern void func_01EA9988(s32);
extern void func_01EAB690(void *);

u64 func_01E9DDD0(s32 *arg0) {
    s32 buf[9];
    u64 var_v0;

    var_v0 = 0x17;
    if (arg0 != 0) {
        func_0011A518(arg0, 0, 0x6C);
        func_01EAB690(buf);
        func_01EA9988(buf[8]);
        arg0[2] = 1;
        arg0[0] = 1;
        arg0[24] = 0;
        arg0[23] = 0;
        arg0[1] = 0;
        arg0[3] = -1;
        var_v0 = 0;
    }
    return var_v0;
}
