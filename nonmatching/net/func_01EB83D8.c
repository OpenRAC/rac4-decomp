/* Not matching yet: SIZE ours 156 / retail 172 (tools/try_func.py func_01EB83D8 --diff) (tools/try_func.py func_01EB83D8 --diff). Not part of the build. */
typedef struct {
    void *buf;
    s32 len;
    u8 pad[0x38];
    s32 f40;
    s32 f44;
} Buf;

extern s16 func_01EB8E98(s32 arg0, s32 arg1);
extern s32 func_01EBAEE0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, Buf *arg4);

s32 func_01EB83D8(u8 *arg0, s8 arg1) {
    Buf b;
    s16 v;
    s32 r;

    v = func_01EB8E98(2, 4);
    r = 2;
    if (arg0 != 0) {
        b.f44 = 0;
        b.buf = &v;
        b.f40 = 0;
        b.len = 4;
        *(s32 *)(arg0 + 0x1B8) = arg1;
        b.f40 += 4;
        b.f44 += 1;
        r = func_01EBAEE0(arg0, 0, 0, 0xF000, &b);
        if (r == 0 || r == 0xD2F3) {
            r = 0;
        }
    }
    return r;
}
