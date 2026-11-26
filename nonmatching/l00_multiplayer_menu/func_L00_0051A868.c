/* Not matching yet: BYTES 8/228 (tools/try_func.py func_L00_0051A868 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
extern s32 func_00540E48();
extern s32 func_00540E50(s32);
extern s32 func_L00_0051C290(s32, s32, s32);
extern s32 func_L00_0051C910(u32);
extern s32 func_L00_0051C9C8(s32);

s32 func_L00_0051A868(s32 arg0) {
    s32 h = func_00540E48();
    s32 a = func_L00_0051C910(h);
    s32 v;
    s32 r;

    if (func_L00_0051C290(a, 1, arg0) == 0)
        return 0;
    v = func_L00_0051C290(func_L00_0051C9C8(h), 1, arg0);
    if (v == 0)
        return 0;
    r = func_00540E50(arg0);
    if (h != r && r != 0) {
        if (func_L00_0051C290(func_L00_0051C910(r), 0x8001, a) == 0)
            return 0;
        v = func_L00_0051C290(func_L00_0051C9C8(r), 0x8001, a);
    }
    return v;
}
