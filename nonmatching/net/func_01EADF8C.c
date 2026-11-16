/* Not matching yet: BYTES 14/44 (tools/try_func.py func_01EADF8C --diff) (tools/try_func.py func_01EADF8C --diff). Not part of the build. */
/* cflags: @sn114 -O2 -G8 */
extern void func_01EADA78(s64, s64);
extern void func_01EADE5C(void);

void func_01EADF8C(s64 arg0, s64 arg1, s64 arg2, s64 arg3) {
    s64 tmp[2];

    tmp[0] = arg0;
    tmp[1] = arg3;
    func_01EADE5C();
    func_01EADA78(tmp[0], tmp[1]);
}
