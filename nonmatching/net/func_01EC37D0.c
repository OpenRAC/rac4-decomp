/* Not matching yet: SIZE ours 92 / retail 84 (tools/try_func.py func_01EC37D0 --diff). Not part of the build. */
extern s32 func_01EC3460(void);
extern s32 func_01EC3498(void);
extern s32 func_01EC47A8(u32, s32);

s32 func_01EC37D0(s32 arg0, s32 arg1)
{
    s32 r = func_01EC3460();

    if (r != 0) {
        return r;
    }
    r = func_01EC47A8(arg0, arg1);
    func_01EC3498();
    return r;
}
