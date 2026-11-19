/* Not matching yet: SIZE ours 80 / retail 72 (tools/try_func.py func_01EA9DE0 --diff). Not part of the build. */
extern s32 func_01EA9FE8(void *object);

s32 func_01EA9DE0(u8 *arg0) {
    s32 result = 2;
    u8 value;

    if (arg0 != 0) {
        value = *arg0;
        if (value == 1) {
            result = func_01EA9FE8(arg0);
            if (result == 0) {
                *arg0 = 0;
            }
        }
    }
    return result;
}
