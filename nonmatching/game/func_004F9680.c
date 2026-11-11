/* Not matching yet: BYTES 4/228 (tools/try_func.py func_004F9680 --diff). Not part of the build. */
/* cflags: -fno-opt-stack */
extern u32 *D_221E20;
void func_004F8F30();

/* Builds a packet via func_004F8F30 after a 16-byte header and fills the header in. */
void func_004F9680(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    u32 *start;
    u32 *cur;
    u32 n;

    start = D_221E20 + 4;
    cur = start;
    func_004F8F30(&cur, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    n = ((u32)cur - (u32)start) >> 4;
    D_221E20[0] = n | 0x10000000;
    D_221E20[1] = 0;
    D_221E20[2] = 0;
    D_221E20[3] = n | 0x50000000;
    D_221E20 += (n << 2) + 4;
}
